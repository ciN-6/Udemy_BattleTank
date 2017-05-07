// Copyright ciN.

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
class AProjectile;


UCLASS(ClassGroup = (BattleTank), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

  /**********
  * Methods *
  **********/

	// Sets default values for this component's properties
	UTankAimingComponent();

  //method for aiming.
  void AimAt(FVector HitLocation);

  //Initializer
  UFUNCTION(BlueprintCallable, Category = "Setup")
  void Init(UTankBarrel* InBarrel, UTankTurret* InTurret);

  UFUNCTION(BlueprintCallable, Category = InputControls)
  void Fire();

protected:

  /*************
  * Properties *
  *************/

  // Holder for the AimingComponent state.
  UPROPERTY(BlueprintReadOnly, Category = "State")
  EFiringState FiringState = EFiringState::Ready;
  
  //The Launch speed of the fired projectile.
  UPROPERTY(EditDefaultsOnly, Category = Firing)
  float LaunchVelocity = 8000.f;

  // how much time to wait before firing again.
  UPROPERTY(EditDefaultsOnly, Category = "Firing")
  float ReloadTime = 3.f;

  // The projectile blueprint;
  UPROPERTY(EditDefaultsOnly, Category = "Setup")
  TSubclassOf<AProjectile> ProjectileBlueprint;
  
  // stores the last time this tank fired.
  double LastFireTime = 0;

private:

  /*************
  * Properties *
  *************/

  // The Barrel Mesh
  UTankBarrel* Barrel = nullptr;
  //The Turret of the Tank
  UTankTurret* Turret = nullptr;
  

  /**********
  * Methods *
  **********/

  // Moves the Barrel Mesh.
  void MoveBarrel(FVector AimDirection);

	
};
