// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankAIController.h"

#include "Controller/TankPlayerController.h"






void ATankAIController::BeginPlay() {
  Super::BeginPlay();

  ATank* ControlledTank = GetControlledTank();
  if (ControlledTank) {
    UE_LOG(LogTemp, Warning, TEXT("Enemy is controlling tank : %s"), *(ControlledTank->GetName()));
  }
  else {
    UE_LOG(LogTemp, Error, TEXT("Missing a Tank for the AIcontroller;"));
  }


  ATank* PlayerTank = GetPlayerTank();
  if (PlayerTank) {
    UE_LOG(LogTemp, Warning, TEXT("Targetting : %s"), *(PlayerTank->GetName()));
  }
  else {
    UE_LOG(LogTemp, Error, TEXT("Cant find humans."));
  }




}

ATank * ATankAIController::GetPlayerTank() const
{

  ATankPlayerController* PlayerController = (ATankPlayerController*)GetWorld()->GetFirstPlayerController();
  if (!PlayerController) {
    UE_LOG(LogTemp, Error, TEXT("Missing a Human controller"));
    return nullptr;
  }

  ATank* Tank = PlayerController->GetControlledTank();
  return Tank;
}

ATank* ATankAIController::GetControlledTank() const {

  return Cast<ATank>(GetPawn());

}