// Copyright ciN.

#pragma once


#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;
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


  // The Aiming Component for barrel movement;
  UTankAimingComponent* AimingComponent = nullptr;

  void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

};
