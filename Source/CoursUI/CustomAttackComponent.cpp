// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomAttackComponent.h"

// Sets default values for this component's properties
UCustomAttackComponent::UCustomAttackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCustomAttackComponent::BeginPlay()
{
	Super::BeginPlay();
	Init();
	// ...
	
}


// Called every frame
void UCustomAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!canAttack)
		currentTime = IncreaseTime(currentTime, maxTime);
	// ...
}

void UCustomAttackComponent::Init()
{
	customOwner = Cast<APawn>(GetOwner());
}

float UCustomAttackComponent::IncreaseTime(float _current, const float& _max)
{
	_current += GetWorld()->DeltaTimeSeconds;
	if (_current >= _max) {
		_current = 0;
		SetCanAttack(true);
	}
	return _current;
}

void UCustomAttackComponent::DecreaseCurrentAmo(const int& _numberToRemove)
{
	currentAmmo -= _numberToRemove;
	currentAmmo = currentAmmo < 0 ? 0 : currentAmmo;
	if (currentAmmo <= 0)
		SetHasAmmoInMagazine(false);
	onCurrentAmmoUpdated.Broadcast(currentAmmo);
}

void UCustomAttackComponent::Attack()
{
	if (!canAttack || !hasAmmo)return;
	const FVector _spawnLoc = customOwner->GetActorLocation() +
		customOwner->GetActorForwardVector() + forwardSpawnOffset +
		customOwner->GetActorUpVector() + upSpawnOffset;
	GetWorld()->SpawnActor<AProjectile>(projectileToSpawn,_spawnLoc, customOwner->GetActorRotation());
	SetCanAttack(false);
	DecreaseCurrentAmo(1);
}

void UCustomAttackComponent::Reload()
{
	currentAmmo = maxAmmo;
	onCurrentAmmoUpdated.Broadcast(currentAmmo);
	SetHasAmmoInMagazine(true);
}
