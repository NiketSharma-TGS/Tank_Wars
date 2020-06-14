// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
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

	bool bHaveProjectileSolution = UGameplayStatics::SuggestProjectileVelocity(

		this,
		OUTLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if(bHaveProjectileSolution)

	{
		auto AimDirection = OUTLaunchVelocity.GetSafeNormal(); //Turns it into a Unit Vector.
		
		MoveBarrelTowards(AimDirection);

	}

	return;
}


void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	//Rotate the barrel in X,Y,Z to meet the AimDirection

	auto BarrelRotator = Barrel->GetForwardVector().Rotation(); //X direction vector where the barrel is facing
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(5); //Calling this through the forward declaration made for TankBarrel
	
	//Change Rotation values of Barrel Rotator according to hit Delta Rotator 
	//with a max. Elevation speed 
	
}
