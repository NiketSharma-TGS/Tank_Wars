// Fill out your copyright notice in the Description page of Project Settings.


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

	//Get world location
	//
}