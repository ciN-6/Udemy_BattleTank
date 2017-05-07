// Copyright ciN.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

/**
 *
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController {
  GENERATED_BODY()

public:

  /**********
  * Methods *
  **********/

  virtual void BeginPlay() override;

  virtual void Tick(float DeltaSeconds) override;

protected:

  /*************
  * Properties *
  *************/


  UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
  void FoundAimingComponent(UTankAimingComponent* AimingComponentRef);

protected:

  /*************
  * Properties *
  *************/

  UPROPERTY(EditDefaultsOnly)
    float CrossairXLoc = .5f;
  UPROPERTY(EditDefaultsOnly)
    float CrossairYLoc = .3333f;
  UPROPERTY(EditDefaultsOnly)
    float LineTraceRange = 1000000.0f;

  // The Aiming Component for barrel movement;
  UTankAimingComponent* AimingComponent = nullptr;

private:

  /**********
  * Methods *
  **********/

  // make the barrel move towards the crossairs.
  void AimTowardsCrosshair();
  // Cast a ray and get it's HitLocation info as the out param
  bool GetSightRayHitLocation(FVector& OutHitLocation) const;
  // Returns a normalized FVector based on a point on the screen shooting forward.
  bool GetLookDirection(FVector2D ScreenPoint, FVector & OutLookDirection) const;

  bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;


};
