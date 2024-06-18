// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayGameMode.h"
#include "TrapManager.h"

void APlayGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	Init();
}

void APlayGameMode::Init()
{
	if (!trapManager) {
		trapManager = GetWorld()->SpawnActor<ATrapManager>(trapManagerToSpawn);
	}
}
