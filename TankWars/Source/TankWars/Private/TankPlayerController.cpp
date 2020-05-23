// Fill out your copyright notice in the Description page of Project Settings.

#include "Math/Vector2D.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Debug Log: Possesion Failed"));
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Debug Log: Possessed Tank: %s"), *(ControlledTank->GetName())); 
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimAtCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());   //This should return the pawn the PlayerController is currently possesing
	
} 

void ATankPlayerController::AimAtCrosshair()
{
	if (!GetControlledTank()) 
	{
		return;
	}

	FVector HitLocation; 

	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Crosshair Direction: %s"), *HitLocation.ToString());
	}
	
	
	//Get world location

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OUTHitLocation) const
{
	float VpSizeX, VpSizeY;

	FVector2D ScreenLocation = FVector2D(VpSizeX * CrossHairXLocation, VpSizeY * CrossHairYLocation);

	//Find the crosshair position
	//"De-Project the screen position of the crosshair to a world direction"
	//Line trace along that look direction and see what we hit upto a range

	return true;
}