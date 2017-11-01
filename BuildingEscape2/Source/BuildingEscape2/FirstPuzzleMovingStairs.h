// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h" //TODO Remove once the code is finished
#include "Engine/TriggerVolume.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "FirstPuzzleMovingStairs.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FStairEvent);

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

	UPROPERTY(BlueprintAssignable)
		FStairEvent OnUpRequest;
	UPROPERTY(BlueprintAssignable)
		FStairEvent OnDownRequest;

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
