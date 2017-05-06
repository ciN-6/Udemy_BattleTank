// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

  virtual void BeginPlay() override;

  virtual void Tick(float DeltaSeconds) override;

  // Get the Tank for this controller
  ATank* GetControlledTank() const;

private:

  UPROPERTY(EditDefaultsOnly)
  float CrossairXLoc = .5f;  
  UPROPERTY(EditDefaultsOnly)
  float CrossairYLoc = .3333f;
  UPROPERTY(EditDefaultsOnly)
  float LineTraceRange = 1000000.0f;

  // make the barrel move towards the crossairs.
  void AimTowardsCrosshair();
  // Cast a ray and get it's HitLocation info as the out param
  bool GetSightRayHitLocation(FVector& OutHitLocation) const;
  // Returns a normalized FVector based on a point on the screen shooting forward.
  bool GetLookDirection(FVector2D ScreenPoint, FVector & OutLookDirection) const;

  bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;
  
};
