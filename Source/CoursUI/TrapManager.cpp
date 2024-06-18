// Fill out your copyright notice in the Description page of Project Settings.


#include "TrapManager.h"

// Sets default values
ATrapManager::ATrapManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATrapManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrapManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATrapManager::AddElement(TObjectPtr<ACorrTrap> _trap)
{
	if (Exist(_trap))return;
	allTraps.Add(_trap);
}

void ATrapManager::RemoveElement(TObjectPtr<ACorrTrap> _trap)
{
	if (!Exist(_trap))return;
	allTraps.Remove(_trap);
}

void ATrapManager::RemoveElement(const int& _index)
{
	if (!Exist(_index))return;
	allTraps.RemoveAt(_index);
}

TObjectPtr<ACorrTrap> ATrapManager::GetElement(const int& _index)
{
	if (!Exist(_index))return nullptr;
	return allTraps[_index];
}

bool ATrapManager::Exist(TObjectPtr<ACorrTrap> _trap)
{
	const int32 _index = allTraps.Find(_trap);
	return _index != INDEX_NONE;
}

bool ATrapManager::Exist(const int& _index)
{
	if (_index <0 || _index > allTraps.Num())return false;
	ACorrTrap* _trap = allTraps[_index];
	if (!_trap)
		return true;
	return false;
}

