// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankPlayerController.h"

#include <sstream>


void ATankPlayerController::Tick(float DeltaSeconds) {

  Super::Tick(DeltaSeconds);
  AimTowardsCrosshair();
}


void ATankPlayerController::BeginPlay() {
  Super::BeginPlay();

  UTankAimingComponent* AimingComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();
  if (ensure(AimingComponent)) {
    FoundAimingComponent(AimingComponent);
  }
  else {
    UE_LOG(LogTemp, Error, TEXT("Missing AimingComponent"));
  }
}

ATank* ATankPlayerController::GetControlledTank() const {
  return Cast<ATank> (GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {

  if (!ensure(GetControlledTank())) { return; }
  FVector HitLocation;
  if (GetSightRayHitLocation(HitLocation)) {
    GetControlledTank()->AimAt(HitLocation);
  }
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const{

  int32 ViewportXSize;
  int32 ViewportYSize;
  FVector2D CrosshairLocation;
  FVector LookDirection;
  
  GetViewportSize(ViewportXSize, ViewportYSize);
  CrosshairLocation = FVector2D(ViewportXSize*CrossairXLoc, ViewportYSize*CrossairYLoc);
  
  if (GetLookDirection(CrosshairLocation, LookDirection)) {
    GetLookVectorHitLocation(LookDirection, OutHitLocation);
  }

  return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const {
  
  FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetControlledTank());
  
  FHitResult HitResult;
  FVector CamLocation = PlayerCameraManager->GetCameraLocation();

  GetWorld()->LineTraceSingleByChannel(
    HitResult,
    CamLocation,
    CamLocation+LookDirection*LineTraceRange,
    ECollisionChannel::ECC_Visibility,
    TraceParams);

    OutHitLocation = HitResult.Location;

  return true;
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenPoint, FVector& OutLookDirection) const {

  FVector Location;
  return DeprojectScreenPositionToWorld(ScreenPoint.X, ScreenPoint.Y, Location, OutLookDirection);
  
}

