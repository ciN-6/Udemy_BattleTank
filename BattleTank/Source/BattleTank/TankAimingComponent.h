// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

  //method for aiming.
  void AimAt(FVector HitLocation, float LaunchSpeed);

  //Setter for the Barrel.
  void SetBarrelReference(UTankBarrel* BarrelToSet);

  //Setter for the Turret
  void SetTurretReference(UTankTurret* TurretToSet);

private:

  // The Barrel Mesh
  UTankBarrel* Barrel = nullptr;
  
  //The Turret of the Tank
  UTankTurret* Turret = nullptr;
  
  // Moves the Barrel Mesh.
  void MoveBarrel(FVector AimDirection);

  // Rotates the Turret mesh
  void MoveTurret(FVector AimDirection);
	
};
