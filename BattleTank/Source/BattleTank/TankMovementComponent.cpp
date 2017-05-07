// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"



UTankMovementComponent::UTankMovementComponent() {
  
}


void UTankMovementComponent::IntendMoveForward(float Throw) {
  LeftTrack->SetThrottle(Throw);
  RightTrack->SetThrottle(Throw);
}


void UTankMovementComponent::IntendTurnRight(float Throw) {

  LeftTrack->SetThrottle(Throw);
  RightTrack->SetThrottle(-Throw);
}


void UTankMovementComponent::Init(UTankTrack* InLeftTrack, UTankTrack* InRightTrack) {

  if (!ensure(InLeftTrack && InRightTrack))
  {
    UE_LOG(LogTemp, Error, TEXT("UTankMovementComponent::Init -- Missing Tracks."));
  }
  LeftTrack = InLeftTrack;
  RightTrack = InRightTrack;

}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) {

  FVector CurrentForwardDirection = GetOwner()->GetActorForwardVector().GetSafeNormal();
  FVector IntendedDirection = MoveVelocity.GetSafeNormal();


  float ForwardThrow = FVector::DotProduct(CurrentForwardDirection, IntendedDirection);
  float TurnThrow = FVector::CrossProduct(CurrentForwardDirection,IntendedDirection).Z;

  IntendMoveForward(ForwardThrow);
  IntendTurnRight(TurnThrow);




}