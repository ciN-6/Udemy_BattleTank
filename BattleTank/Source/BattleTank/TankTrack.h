// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Controls how the Tracks of the tank behaves.
 */
UCLASS(ClassGroup = (BattleTank), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:

  UFUNCTION(BlueprintCallable, Category = Input)
  void SetThrottle(float Throttle);
	
  // How much force is applied in Newtons.
  UPROPERTY(EditDefaultsOnly)
  float TrackMaxDrivingForce = 400000.f;
	
};
