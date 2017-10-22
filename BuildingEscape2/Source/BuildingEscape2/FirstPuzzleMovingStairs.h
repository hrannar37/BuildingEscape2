// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "Engine/World.h" //TODO Remove once the code is finished
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "FirstPuzzleMovingStairs.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE2_API UFirstPuzzleMovingStairs : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFirstPuzzleMovingStairs();
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void MoveStairsDown();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	FVector InitialPosition = GetOwner()->GetActorLocation();
	
};