// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"



void UTankTurret::Rotate(float RelativeSpeed) {

  RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
  float ElevationChange = RelativeSpeed * MaxDegreePerSeconds * GetWorld()->DeltaTimeSeconds;
  float RawNewElevation = RelativeRotation.Pitch + ElevationChange;
  SetRelativeRotation(FRotator(0,RawNewElevation,0));

}
