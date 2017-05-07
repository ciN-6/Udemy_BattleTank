// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"

// TODO Move below to AimingComponent
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
// TODO Remove Above

#include "Tank.h"




// Sets default values
ATank::ATank()
{
  PrimaryActorTick.bCanEverTick = false;
}


// Called when the game starts or when spawned
void ATank::BeginPlay()
{
  Super::BeginPlay();
  TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}


void ATank::AimAt(FVector HitLocation) {
  if (!ensure(TankAimingComponent)) { return; }
  TankAimingComponent->AimAt(HitLocation, LauchingVelocity);
}

void ATank::Shoot() {

  if (!ensure(Barrel)) { return; }
  
  bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTime;
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