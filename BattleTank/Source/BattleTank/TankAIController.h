// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	

public:
  
  // Distance where to stop moving when close enough to the goal.
  UPROPERTY(EditDefaultsOnly, Category = Setup)
  float CloseEnoughDistance = 3000.f;


private:
  void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

};
