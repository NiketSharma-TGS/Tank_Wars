// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAiController.h"


void ATankAiController::BeginPlay()
{

	Super::BeginPlay();

	auto ControlledTank = GetAiControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ai Controlled Tank failed"));
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Debug Log: Ai Possessed Tank: %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankAiController::GetAiControlledTank() const
{

	return Cast<ATank>(GetPawn());
}