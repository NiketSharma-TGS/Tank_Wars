// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class TANKWARS_API ATank : public APawn
{
	GENERATED_BODY()

public:

	
	//Location of what we want to hit & Location of obj. found through the aiming function in TankPlayerCotroller
	void AimAt(FVector HitLocation); 

	UFUNCTION(BlueprintCallable, Category=Setup)
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

private:

	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UStaticMeshComponent* Barrel = nullptr;

protected:

	UTankAimingComponent* TankAimingComponent = nullptr;

};
