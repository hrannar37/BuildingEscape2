// Fill out your copyright notice in the Description page of Project Settings.

#include "PortalTeleporting.h"


// Sets default values for this component's properties
UPortalTeleporting::UPortalTeleporting()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPortalTeleporting::BeginPlay()
{
	Super::BeginPlay();

	FString Owner = GetOwner()->GetName();
	Player = GetWorld()->GetFirstPlayerController()->GetCharacter();
	if (!PortalOut)
	{
		UE_LOG(LogTemp, Error, TEXT("Out Portal is not defined on %s"), *Owner)
			return;
	}
	if (!Player)
	{
		UE_LOG(LogTemp, Error, TEXT("Cant Find A Player"))
			return;
	}

		UE_LOG(LogTemp, Error, TEXT("Player is "))
	
}


// Called every frame
void UPortalTeleporting::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPortalTeleporting::Teleporting()
{
}

