// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * {"DraggedEntityType":"Todoist.ViewModel.ViewEntities.ToDoInListInView, Todoist.ViewModel, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null","EntityIds":[376]}
 */
UCLASS()
class TANKWARS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevate(float DegPerSec);

private:
	UPROPERTY(EditAnywhere)
		float MaxDegreePerSecond = 20; //Fix values later

};
