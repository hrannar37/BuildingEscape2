// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h" //TODO Remove once the code is finished
#include "Kismet/GameplayStatics.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "PortalTeleporting.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE2_API UPortalTeleporting : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPortalTeleporting();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void Teleporting();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	UPROPERTY(EditAnywhere)
		AActor* PortalOut = nullptr;

	ACharacter* Player = nullptr;
};
