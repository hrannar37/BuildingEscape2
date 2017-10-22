// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstPuzzleMovingStairs.h"
//#include "Engine/World.h" //TODO Remove once the code is finished

// Sets default values for this component's properties
UFirstPuzzleMovingStairs::UFirstPuzzleMovingStairs()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFirstPuzzleMovingStairs::BeginPlay()
{
	Super::BeginPlay();

	MoveStairsDown();
	// ...
	
}


// Called every frame
void UFirstPuzzleMovingStairs::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UFirstPuzzleMovingStairs::MoveStairsDown()
{
	GetOwner()->SetActorLocation(InitialPosition - (0.0f, 0.0f, -30.0f));
}


