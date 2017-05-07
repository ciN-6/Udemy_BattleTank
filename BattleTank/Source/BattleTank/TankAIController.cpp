// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Controller/TankPlayerController.h"


void ATankAIController::BeginPlay() {
  Super::BeginPlay();
}


void ATankAIController::Tick(float DeltaSeconds) {

  
  Super::Tick(DeltaSeconds); 
  
  if (!AimingComponent) {
    // In case of respawn, AimingComponant must be reaquired.
    AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
    if (!ensure(AimingComponent)) { return; }
  }

  APawn* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
  if (!ensure(PlayerTank)) { return; }  
  APawn* OwnTank = GetPawn();
  if (!ensure(OwnTank)) { return; }

  MoveToActor(PlayerTank, CloseEnoughDistance);
  AimingComponent->AimAt(PlayerTank->GetActorLocation());
  AimingComponent->Fire();
}






