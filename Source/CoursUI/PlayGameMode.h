// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlayGameMode.generated.h"

/**
 * 
 */
class ATrapManager;
UCLASS()
class COURSUI_API APlayGameMode : public AGameModeBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TSubclassOf<ATrapManager> trapManagerToSpawn = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<ATrapManager> trapManager = nullptr;

public:
	TObjectPtr<ATrapManager> GetTrapManager() const { return trapManager; }

private:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage);
	void Init();
};
