// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class COURSUI_API AProjectile : public AActor
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	UPROPERTY(EditAnywhere)
		float moveSpeed = 1600;
	UPROPERTY(EditAnywhere)
		float lifespan = 5;
	UPROPERTY(EditAnywhere)
		float forwardOffset = 300;
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
		void OverLapAction(AActor* _this, AActor* _overlap);
	void Move();
	void Init();

public:	
	// Called every frame

};
