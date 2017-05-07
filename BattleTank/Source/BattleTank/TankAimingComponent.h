// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UENUM()
enum class EFiringState : uint8 {
  Reloading,
  Moving,
  Ready
};

class UTankBarrel;
class UTankTurret;

UCLASS(ClassGroup = (BattleTank), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

  //method for aiming.
  void AimAt(FVector HitLocation, float LaunchSpeed);

  //Initializer
  UFUNCTION(BlueprintCallable, Category = "Setup")
  void Init(UTankBarrel* InBarrel, UTankTurret* InTurret);

protected:

  // Holder for the AimingComponent state.
  UPROPERTY(BlueprintReadOnly, Category = "State")
  EFiringState FiringState = EFiringState::Ready;


private:

  // The Barrel Mesh
  UTankBarrel* Barrel = nullptr;
  
  //The Turret of the Tank
  UTankTurret* Turret = nullptr;
  
  // Moves the Barrel Mesh.
  void MoveBarrel(FVector AimDirection);

	
};
