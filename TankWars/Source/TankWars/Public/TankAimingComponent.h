// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKWARS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UTankAimingComponent();

	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

	//Add SetTurretRef() later

	void AimAt(FVector HitLocation, float LaunchSpeed);

	

private: 
	
	UStaticMeshComponent* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection); //Move Barrel towards the AimDirection
};
