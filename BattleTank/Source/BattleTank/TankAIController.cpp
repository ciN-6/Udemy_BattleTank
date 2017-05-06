// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankAIController.h"
#include "Tank.h"
#include "Controller/TankPlayerController.h"


void ATankAIController::BeginPlay() {
  Super::BeginPlay();
}




void ATankAIController::Tick(float DeltaSeconds) {

  ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
  if (!PlayerTank) { return; }
  ATank* OwnTank = Cast<ATank>(GetPawn());
  if (!OwnTank) { return; }

  Super::Tick(DeltaSeconds);
  OwnTank->AimAt(PlayerTank->GetActorLocation());
  OwnTank->Shoot();
}






