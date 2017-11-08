// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstPuzzleMovingStairs.h"




// Sets default values for this component's properties
UFirstPuzzleMovingStairs::UFirstPuzzleMovingStairs()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
}


// Called when the game starts
void UFirstPuzzleMovingStairs::BeginPlay()
{
	Super::BeginPlay();
	
	if (!PressurePlate)
	{
		UE_LOG(LogTemp, Error, TEXT("Pressure Plate is not defined"))
			return;
	}


	
	// ...
	
}


// Called every frame
void UFirstPuzzleMovingStairs::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!PressurePlate) { return; }
	if (PressurePlate->IsOverlappingActor(Key))
	{
		OnUpRequest.Broadcast();
	}
	else { OnDownRequest.Broadcast(); }
}


