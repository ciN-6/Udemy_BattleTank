// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * hold barrel properties
 */
UCLASS(ClassGroup = (BattleTank), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	

public :
  void Elevate(float RelativeSpeed);

private:
  
  UPROPERTY(EditDefaultsOnly, Category=Setup)
  float MaxDegreePerSeconds = 10;

  UPROPERTY(EditDefaultsOnly, Category = Setup)
  float MaxElevation = 40;

  UPROPERTY(EditDefaultsOnly, Category = Setup)
  float MinElevation = 0;

	
};
