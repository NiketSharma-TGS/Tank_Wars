// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * {"DraggedEntityType":"Todoist.ViewModel.ViewEntities.ToDoInListInView, Todoist.ViewModel, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null","EntityIds":[376]}
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKWARS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category =  Setup)
		float DegreePerSecond = 30; //Fix values later

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegree = 30; //Fix values later 

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinDegree = 0; //Fix values later
};
