// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	//ActorThatOpens is defined as editableanywhere, but we need to define it at runtime.
	//search top down, find from the world at runtime, the fpscontroller and from there get the pawn.
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	Owner = GetOwner();
	// ...
	
}

void UOpenDoor::OpenDoor()
{
	//Find Owning actor
	
	//create rotator

													   //set door rotation
	Owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));//pitch, yaw, roll.
}

void UOpenDoor::CloseDoor()
{
	Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
}



// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	//poll trigger volume
	//if the ActorThatOpens is in the volume
		if (PressurePlate->IsOverlappingActor(ActorThatOpens))
		{
			OpenDoor();
			LastDoorOpenTime = GetWorld()->GetTimeSeconds();
		}
	
		if (GetWorld()->GetTimeSeconds() > (LastDoorOpenTime + DoorCloseDelay)) {
			CloseDoor();

		}
	

	//check if it's time to close the door
}

