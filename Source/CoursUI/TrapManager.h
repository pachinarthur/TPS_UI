// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrapManager.generated.h"
class ACorrTrap;
UCLASS()
class COURSUI_API ATrapManager : public AActor
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TArray<TObjectPtr<ACorrTrap>> allTraps;

public:
	TArray<TObjectPtr<ACorrTrap>> GetAllTraps() { return allTraps; }
public:	
	// Sets default values for this actor's properties
	ATrapManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:	
	void AddElement(TObjectPtr<ACorrTrap> _trap);
	void RemoveElement(TObjectPtr<ACorrTrap> _trap);
	void RemoveElement(const int& _index);
	TObjectPtr<ACorrTrap>GetElement(const int& _index);
	bool Exist(TObjectPtr<ACorrTrap> _trap);
	bool Exist(const int& _index);
};
