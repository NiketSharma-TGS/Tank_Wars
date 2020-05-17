// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKWARS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;  //Tank is a Parent Pawn class to Tank_BP and ATank comes from it

	void BeginPlay() override;  //Not declaring a new method, overriding a virtual one that was defined in a Parent Class i.e. AActor
	
};
