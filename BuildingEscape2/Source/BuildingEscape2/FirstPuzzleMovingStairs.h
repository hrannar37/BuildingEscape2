// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h" //TODO Remove once the code is finished
#include "Engine/TriggerVolume.h"
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
	
	FVector InitialPosition;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void MoveStairsDown(FVector);
	void ResetStairs(FVector);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
private:

	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;
	UPROPERTY(EditAnywhere)
		AActor* Key = nullptr;


	AActor* Player = nullptr;

};
