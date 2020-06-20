// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "Tank.h"
#include "TankAiController.h"


void ATankAiController::BeginPlay()
{

	Super::BeginPlay();

	auto ControlledTank = GetPlayerTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ai could not get the Player Tank"));
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Debug Log: Ai got the Player Tank: %s"), *(ControlledTank->GetName()));
	}
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Move towards the player
	AiTarget(); //This aims at the player
	//Fire if Ready

}

ATank* ATankAiController::GetAiControlledTank() const
{

	return Cast<ATank>(GetPawn());
}

ATank* ATankAiController::GetPlayerTank()
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn(); //Gets the name of FP Camera controller
	if (!PlayerTank)
	{
		return nullptr;
	}

	else
	{
		return Cast<ATank>(PlayerTank); //GetsFPController would return a PC, GetPawn returns a Pawn which we need
	}
}

void ATankAiController::AiTarget()
{
	auto PlayerTank = GetPlayerTank();
	auto PlayerTankLocation = PlayerTank->GetActorLocation();
	//auto AiTankName = GetOwner()->GetName();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ai failed to aim at player Tank"));
	}
	
	else
	{

		GetAiControlledTank()->AimAt(PlayerTankLocation); //Can't log here because this gets called every tick
	}
}
