// Copyright ciN.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"


class UTankTrack;
/**
 *
 */
UCLASS(ClassGroup = (BattleTank), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
  GENERATED_BODY()

public:

  UTankMovementComponent();

  UFUNCTION(BlueprintCallable, Category = Setup)
  void Init(UTankTrack* LeftTrack, UTankTrack* RightTrack);

  // Controls the forwards.
  UFUNCTION(BlueprintCallable, Category = Input)
  void IntendMoveForward(float Throw);

  // Controls how much right we try to turn.
  UFUNCTION(BlueprintCallable, Category = Input)
  void IntendTurnRight(float Throw);

  virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

private:

  UTankTrack* LeftTrack = nullptr;
  UTankTrack* RightTrack = nullptr;
};
