// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{

	if (!Barrel)
	{
		return;
	}

	FVector OUTLaunchVelocity(0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile")); //This searches for a socket named Projectile, created on Barrel.FBX

	//Calculate the OUTLaunchVelocity

	if (UGameplayStatics::SuggestProjectileVelocity(

		this,
		OUTLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace

	))

	{
		auto AimDirection = OUTLaunchVelocity.GetSafeNormal(); //Turns it into a Unit Vector.
		auto TankName = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *TankName, *AimDirection.ToString());

	}

	return;
}


	void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}