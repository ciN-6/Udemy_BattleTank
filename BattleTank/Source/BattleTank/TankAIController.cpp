// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankAIController.h"
#include "Tank.h"
#include "Controller/TankPlayerController.h"


void ATankAIController::BeginPlay() {
  Super::BeginPlay();
}




void ATankAIController::Tick(float DeltaSeconds) {

  Super::Tick(DeltaSeconds); 
  
  ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
  if (!ensure(PlayerTank)) { return; }
  ATank* OwnTank = Cast<ATank>(GetPawn());
  if (!ensure(OwnTank)) { return; }

  MoveToActor(PlayerTank, CloseEnoughDistance);
  OwnTank->AimAt(PlayerTank->GetActorLocation());
  //OwnTank->Shoot();
}






