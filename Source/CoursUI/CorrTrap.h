// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "CorrTrap.generated.h"

USTRUCT()
struct FCorrTrapSetting
{
	GENERATED_BODY()
public:
		UPROPERTY(EditAnywhere)
			int damage = 1;
		UPROPERTY(EditAnywhere)
			int durability = 10;
public: 
	FCorrTrapSetting() {

	}

	FCorrTrapSetting(int _damage, int _durability) {
		damage = _damage;
		durability = _durability;
	}

	void SetDamage(int _value) {
		damage = _value;
	}
};
UCLASS()
class COURSUI_API ACorrTrap : public AActor
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
			TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UBoxComponent> collider = nullptr;
	UPROPERTY(EditAnywhere)
		FCorrTrapSetting settings = FCorrTrapSetting();

	
	
public:	
	// Sets default values for this actor's properties
	ACorrTrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void OnOverlap(AActor* _this, AActor* _other);

};
