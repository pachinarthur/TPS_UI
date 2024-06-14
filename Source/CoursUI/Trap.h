// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Trap.generated.h"

/**
 * 
 */
UCLASS()
class COURSUI_API ATrap : public ATriggerBox
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		int degats = 3;
protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


public:

	// constructor sets default values for this actor's properties
	ATrap();
	// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(AActor* _overlapped, AActor* _overlap);
};
