// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
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
	GetSightRayHitLocation(HitLocation);

	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Crosshair Direction: %s"), *HitLocation.ToString());
	}
	
	
	//Get world location

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OUTHitLocation) const
{
	int32 VpSizeX, VpSizeY;
	GetViewportSize(VpSizeX, VpSizeY);

	FVector2D ScreenLocation = FVector2D(VpSizeX * CrossHairXLocation, VpSizeY * CrossHairYLocation);

	FVector LookDirection;

	//"De-Project the screen position of the crosshair to a world direction"
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//Line trace along that look direction and see what we hit upto a range
		GetLookVectorHitLocation(OUTHitLocation, LookDirection);
		//UE_LOG(LogTemp, Warning, TEXT("Crosshair Direction: %s"), *LookDirection.ToString());
	}
	
	
	



	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraLocation;

	DeprojectScreenPositionToWorld
	(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraLocation,
		LookDirection
	);

	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector& OUTHitLocation, FVector Direction) const //HitLocation & LookDirection 
{	
	FHitResult HitCheck; 
	auto RayStart = PlayerCameraManager->GetCameraLocation();
	auto RayEnd = RayStart + (Direction * LineTraceRange);
	
	if (GetWorld()->LineTraceSingleByChannel
		(
			HitCheck,
			RayStart,
			RayEnd,
			ECollisionChannel::ECC_Visibility
		)
	)
	{
		OUTHitLocation = HitCheck.Location;	
		return true;
	}

	OUTHitLocation = FVector(0);
	return false; //Line Trace failed
}