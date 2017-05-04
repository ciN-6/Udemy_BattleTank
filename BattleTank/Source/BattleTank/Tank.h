// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
  
  // Sets default values for this pawn's properties
  ATank();

  // move the barrel of the tank toward a location.
  void AimAt(FVector HitLocation);

  // Called to bind functionality to input
  virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
  
  UFUNCTION(BlueprintCallable, Category=Setup)
  void SetBarrelReference(UTankBarrel* Barrel);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

  // A Component used for aiming;
  UTankAimingComponent* TankAimingComponent = nullptr;

  UPROPERTY(EditAnywhere, Category = Firing)
  float LauchingVelocity = 100000.f;



};
