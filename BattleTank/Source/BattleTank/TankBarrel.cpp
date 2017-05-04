// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"




void UTankBarrel::Elevate(float RelativeSpeed) {

  RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
  
  float ElevationChange = RelativeSpeed * MaxDegreePerSeconds * GetWorld()->DeltaTimeSeconds;
  float RawNewElevation = RelativeRotation.Pitch + ElevationChange;
  SetRelativeRotation(FRotator(FMath::Clamp(RawNewElevation, MinElevation, MaxElevation), 0, 0));

  
}
