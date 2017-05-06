// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
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


void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) {
  Barrel = BarrelToSet;
}


void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet) {
  Turret = TurretToSet;
}



void UTankAimingComponent::MoveBarrel(FVector AimDirection) {

  FRotator BarrelRotation = Barrel->GetForwardVector().Rotation();
  FRotator AimAsRotator = AimDirection.Rotation();
  FRotator DeltaRotator = AimAsRotator - BarrelRotation;
  Barrel->Elevate(DeltaRotator.Pitch);

}

void UTankAimingComponent::MoveTurret(FVector AimDirection) {

  FRotator TurretRotation = Turret->GetForwardVector().Rotation();
  FRotator AimAsRotator = AimDirection.Rotation();
  FRotator DeltaRotator = AimAsRotator - TurretRotation;
  Turret->Rotate(DeltaRotator.Yaw);

}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) {

  if (!Barrel) { return; }  
  FVector ReturnedVelocity;
  if (UGameplayStatics::SuggestProjectileVelocity(
    this,
    ReturnedVelocity,
    Barrel->GetSocketLocation(FName("BarrelEnd")),
    HitLocation,
    LaunchSpeed,
    false,
    0.f,
    0.f,
    ESuggestProjVelocityTraceOption::DoNotTrace
  ))
  {

    FVector AimDirection = ReturnedVelocity.GetSafeNormal();
    MoveBarrel(AimDirection);
    MoveTurret(AimDirection);
  }
  

}

