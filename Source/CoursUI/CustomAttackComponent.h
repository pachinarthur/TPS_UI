// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Projectile.h"
#include "CustomAttackComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COURSUI_API UCustomAttackComponent : public UActorComponent
{
	GENERATED_BODY()
		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCurrentAmmoUpdated, int, _value);
	UPROPERTY(BlueprintAssignable,BlueprintCallable)
		FOnCurrentAmmoUpdated onCurrentAmmoUpdated;
protected:
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int currentAmmo = 10;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int maxAmmo = 10;
		UPROPERTY(EditAnywhere)
			bool canAttack = true;
		UPROPERTY(EditAnywhere)
			float currentTime = 0;
		UPROPERTY(EditAnywhere)
			float maxTime = 0.5f;
		UPROPERTY(EditAnywhere)
			TObjectPtr<APawn> customOwner = nullptr;
		UPROPERTY(EditAnywhere)
			bool hasAmmo = true;
		UPROPERTY(EditAnywhere)
			float forwardSpawnOffset = 10;
		UPROPERTY(EditAnywhere)
			float upSpawnOffset = 0;
		UPROPERTY(EditAnywhere)
			TSubclassOf<AProjectile> projectileToSpawn = nullptr;
public:
	FOnCurrentAmmoUpdated& OnCurrentAmmoUpdated() { return onCurrentAmmoUpdated; }
	UFUNCTION(BlueprintCallable)
	int GetCurrentAmmo() const { return currentAmmo; }
	UFUNCTION(BlueprintCallable)
	int GetMaxAmmo() const { return maxAmmo; }
	UFUNCTION(BlueprintCallable)
	int BP_GetCurrentAmmo() const { return GetCurrentAmmo(); }
public:	
	// Sets default values for this component's properties
	UCustomAttackComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Init();
	float IncreaseTime(float _current, const float& _max);
	void DecreaseCurrentAmo(const int& _numberToRemove);
public:	
	void Attack();
	void Reload();
	void SetCanAttack(const bool& _value) { canAttack = _value; };
	void SetHasAmmoInMagazine(const bool& _value) { hasAmmo = _value; }
		
};
