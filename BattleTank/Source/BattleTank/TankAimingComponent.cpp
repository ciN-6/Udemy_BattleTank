// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
  // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
  // off to improve performance if you don't need them.
  PrimaryComponentTick.bCanEverTick = true;

  // ...
}


void UTankAimingComponent::SetBarrelRefence(UStaticMeshComponent* BarrelToSet) {
  Barrel = BarrelToSet;
}



// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
  Super::BeginPlay();

  // ...

}




void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) {

  if (!Barrel) { return; }
  FString ThisTankName = GetOwner()->GetName();
  FVector ReturnedVelocity;
  if (UGameplayStatics::SuggestProjectileVelocity(
    this,
    ReturnedVelocity,
    Barrel->GetSocketLocation(FName("BarrelEnd")),
    HitLocation,
    LaunchSpeed,
    false,0.f,0.f,ESuggestProjVelocityTraceOption::TraceFullPath
  ) ) 
  {
    
    UE_LOG(LogTemp, Warning, TEXT("%s Fires at %s, HITLocation : %s"), *ThisTankName, *ReturnedVelocity.GetSafeNormal().ToString(), *HitLocation.ToString());
  }
  else {
    UE_LOG(LogTemp, Warning, TEXT("%s Cannot find target at %s"), *ThisTankName, *HitLocation.ToString());
  }
  

  
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
  Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
  // ...
}

