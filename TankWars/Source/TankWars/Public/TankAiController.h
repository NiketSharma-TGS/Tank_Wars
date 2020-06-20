// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAiController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class TANKWARS_API ATankAiController : public AAIController
{
	GENERATED_BODY()

public:
	
	void AiTarget();

	ATank* GetAiControlledTank() const;  //ATank because that is what this is returning

private:
	
	void BeginPlay() override; //Declaring this to use functions at Begin-Play event in the implementaion

	virtual void Tick(float DeltaTime) override;

	ATank* GetPlayerTank();
};
