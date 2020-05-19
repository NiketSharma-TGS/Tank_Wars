// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAiController.generated.h"

/**
 * 
 */
UCLASS()
class TANKWARS_API ATankAiController : public AAIController
{
	GENERATED_BODY()

public:
	ATank* GetAiControlledTank() const;  //ATank because that is what this is returning 
	
	void BeginPlay() override; //Declaring this to use functions at Begin-Play event in the implementaion
};
