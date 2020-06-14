// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;

UCLASS()
class TANKWARS_API ATank : public APawn
{
	GENERATED_BODY()

public:

	
	//Location of what we want to hit & Location of obj. found through the aiming function in TankPlayerCotroller
	void AimAt(FVector HitLocation); 

	UFUNCTION(BlueprintCallable, Category=Setup)
		void SetBarrelReference(UTankBarrel* BarrelToSet);

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 10000 ; //Set a suitable value for Initial Projectile Velocity later

private:

	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UTankBarrel* Barrel = nullptr;

protected:

	UTankAimingComponent* TankAimingComponent = nullptr;

};
