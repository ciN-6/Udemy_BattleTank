// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
  // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
  // off to improve performance if you don't need them.
  PrimaryComponentTick.bCanEverTick = true;

  // ...
}


void UTankAimingComponent::Init(UTankBarrel* InBarrel, UTankTurret* InTurret) {
  Barrel = InBarrel; 
  Turret = InTurret;
}


void UTankAimingComponent::MoveBarrel(FVector AimDirection) {

  if (!ensure(Barrel && Turret)) { return;}

  FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
  FRotator AimAsRotator = AimDirection.Rotation();
  FRotator DeltaRotator = AimAsRotator - BarrelRotation;
  Barrel->Elevate(DeltaRotator.Pitch);
  Turret->Rotate(DeltaRotator.Yaw);

}


void UTankAimingComponent::AimAt(FVector HitLocation) {

  FVector ReturnedVelocity;
  if (UGameplayStatics::SuggestProjectileVelocity(
    this,
    ReturnedVelocity,
    Barrel->GetSocketLocation(FName("BarrelEnd")),
    HitLocation,
    LaunchVelocity,
    false,
    0.f,
    0.f,
    ESuggestProjVelocityTraceOption::DoNotTrace
  ))
  {

    FVector AimDirection = ReturnedVelocity.GetSafeNormal();
    MoveBarrel(AimDirection);
  }
  

}

void UTankAimingComponent::Fire() {

  if (!ensure(Barrel && ProjectileBlueprint) ) { return; }

  bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTime;
  if (isReloaded) {
    AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(
      ProjectileBlueprint,
      Barrel->GetSocketLocation(FName("BarrelEnd")),
      Barrel->GetSocketRotation(FName("BarrelEnd"))
      );

    Projectile->LaunchProjectile(LaunchVelocity);
    LastFireTime = FPlatformTime::Seconds();
  }

}