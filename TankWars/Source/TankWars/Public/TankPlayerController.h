// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


class ATank;

UCLASS()
class TANKWARS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;  //Tank is a Parent Pawn class to Tank_BP and ATank comes from it

	//Moves tha barrel to align the shot at crosshair and world intersection
private:


	virtual void BeginPlay() override;  //Not declaring a new method, overriding a virtual one that was defined in a Parent Class i.e. AActor
	
	virtual void Tick(float DeltaTime) override;


	void AimAtCrosshair(); 

	bool GetSightRayHitLocation(FVector& OUTHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	
	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5; //crosshair is 1/2 of the screen in X
	
	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.3333; //corsshair is 1/3 of the screen in Y


	bool GetLookVectorHitLocation(FVector& OUTHitLocation, FVector Direction) const;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 10000000;
};
