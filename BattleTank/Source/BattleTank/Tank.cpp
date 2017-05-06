// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Tank.h"




// Sets default values
ATank::ATank()
{
  // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = false;

  TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::AimAt(FVector HitLocation) {
  TankAimingComponent->AimAt(HitLocation, LauchingVelocity);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet) {
  TankAimingComponent->SetBarrelReference(BarrelToSet);
  this->Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret* Turret) {
  TankAimingComponent->SetTurretReference(Turret);
}


// Called when the game starts or when spawned
void ATank::BeginPlay()
{
  Super::BeginPlay();

}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
  Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::Shoot() {

  
  bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTime;

  if (!Barrel) { return; }

  if (isReloaded) {
    AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(
      ProjectileBlueprint,
      Barrel->GetSocketLocation(FName("BarrelEnd")),
      Barrel->GetSocketRotation(FName("BarrelEnd"))
      );

    Projectile->LaucheProjectile(LauchingVelocity);
    LastFireTime = FPlatformTime::Seconds();
  }


  
  
}