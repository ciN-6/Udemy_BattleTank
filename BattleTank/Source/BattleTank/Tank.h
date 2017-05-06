// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class AProjectile;
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
  
  // Sets default values for this pawn's properties
  ATank();


  // The projectile blueprint;
  UPROPERTY(EditDefaultsOnly, Category = Setup)
  TSubclassOf<AProjectile> ProjectileBlueprint;

  // move the barrel of the tank toward a location.
  void AimAt(FVector HitLocation);

  // Called to bind functionality to input
  virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

  UFUNCTION(BlueprintCallable, Category = InputControls)
  void Shoot();
  
  UFUNCTION(BlueprintCallable, Category = Setup)
  void SetBarrelReference(UTankBarrel* Barrel);

  UFUNCTION(BlueprintCallable, Category = Setup)
  void SetTurretReference(UTankTurret* Turret);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

  // A Component used for aiming;
  UTankAimingComponent* TankAimingComponent = nullptr;

  UPROPERTY(EditDefaultsOnly, Category = Firing)
  float LauchingVelocity = 100000.f;

  // local Barrel
  UTankBarrel* Barrel = nullptr;


  UPROPERTY(EditDefaultsOnly, Category = Firing)
  float ReloadTime = 3.f;

  double LastFireTime = 0;
};
