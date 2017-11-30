// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"


#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	FindPhysicsHandleComponent();
	FString ObjectName = GetOwner()->GetName();
	FString ObjectPos = GetOwner()->GetTransform().GetLocation().ToString();
	
	/// look for attached physics Handle
	
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent) {
		UE_LOG(LogTemp, Warning, TEXT("InputComponent is here"))
			///Bind the input axis
			InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
			InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("%s is missing Input component"), *GetOwner()->GetName())
	}
	
}


void UGrabber::Grab() {
	UE_LOG(LogTemp, Warning, TEXT("Grab key pressed"))
	//line trace and Try and reach any actors with physics body collision channel set
	auto HitResult = GetFirstPhysicsBodyInReach();
	auto ActorHit = HitResult.GetActor();

	auto ComponentToGrab = HitResult.GetComponent();
	//if we hit something then attach a physics handle
	if (ActorHit) {
		//attach physics handle
		PhysicsHandle->GrabComponent(
			ComponentToGrab,
			NAME_None,
			ComponentToGrab->GetOwner()->GetActorLocation(), ///ComponentToGrab or ActorHit
			true
		);
	}
}

void UGrabber::Release() {
	UE_LOG(LogTemp, Warning, TEXT("Grab Released"))
		//TODO release physics handle
}

void UGrabber::FindPhysicsHandleComponent()
{
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle) {
		//Physics handle is found
	}
	else //physics handle is missing
	{

		UE_LOG(LogTemp, Error, TEXT("%s is missing Physics handle"), *GetOwner()->GetName())

	}
}

void UGrabber::SetupInputComponent()
{
}



//TODO log out to test
//UE_LOG(LogTemp, Warning, TEXT("Location: %s, Rotation: %s"), 
//	*PlayerViewPointLocation.ToString(), //whitespace for formatting
//	*PlayerViewPointRotation.ToString() //star to dereference
//) //no semicolo cus macro

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation; // macro OUT does nothing, only used as reminder
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
	
	//if the physics handle is attached
	if (PhysicsHandle->GrabbedComponent) 
	{
		//move the object we're holding
		PhysicsHandle->SetTargetLocation(LineTraceEnd);
	}
		

	

	// ...
}



const FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{
	///get player view  point this tick GetPlayerViewPoint
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation; // macro OUT does nothing, only used as reminder
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);

	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LineTraceEnd,
		FColor(255, 0, 0),
		false,
		0.f,
		0.f,
		1.0f
	);


	///setup query parameters
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	///line trace ray cast to reach distance
	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);
	//ray cast out to reach distance
	///see what we hit 
	AActor* ActorHit = Hit.GetActor();
	if (ActorHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Line trace hit: %s"), *(ActorHit->GetName()))
	}
	return Hit;
}

