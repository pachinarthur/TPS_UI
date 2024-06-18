// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "CustomMovementComponent.h"
#include "CustomAttackComponent.h"
#include "InputMappingContext.h"
#include "PlayerPawn.generated.h"

UCLASS()
class COURSUI_API APlayerPawn : public APawn
{
	GENERATED_BODY()
		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHeatlhUpdated, int, _value);
		UPROPERTY(BlueprintAssignable, BlueprintCallable)
			FOnHeatlhUpdated onHeatlhUpdated;

		UPROPERTY(EditAnywhere,Category="PlayerPawn|Components")
			TObjectPtr<USkeletalMeshComponent> skeleton = nullptr;
		UPROPERTY(EditAnywhere, Category = "PlayerPawn|Components")
			TObjectPtr<USpringArmComponent> springArm = nullptr;
		UPROPERTY(EditAnywhere, Category = "PlayerPawn|Components")
			TObjectPtr<UCameraComponent> camera = nullptr;
protected:
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerPawn|Components")
			TObjectPtr<UCustomMovementComponent> movement = nullptr;
		UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "PlayerPawn|Components")
			TObjectPtr<UCustomAttackComponent> attack = nullptr;

		UPROPERTY(EditAnywhere, Category = "PlayerPawn|Input")
			TObjectPtr<UInputMappingContext> mappingContext = nullptr;
		UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "PlayerPawn|Input")
			TObjectPtr<UInputAction> moveInput = nullptr;
		UPROPERTY(EditAnywhere, Category = "PlayerPawn|Input")
			TObjectPtr<UInputAction> rotateInput = nullptr;
		UPROPERTY(EditAnywhere, Category = "PlayerPawn|Input")
			TObjectPtr<UInputAction> fireInput = nullptr;
		UPROPERTY(EditAnywhere, Category = "PlayerPawn|Input")
			TObjectPtr<UInputAction> reloadInput = nullptr;

		UPROPERTY(EditAnywhere, Category = "PlayerPawn")
			int heatlh = 10;
		UPROPERTY(EditAnywhere, Category = "PlayerPawn")
			int pourcentFull = 10;

public:
	FOnHeatlhUpdated& OnHeatlhUpdated() { return onHeatlhUpdated; }
	// Sets default values for this pawn's properties
	APlayerPawn();

	UFUNCTION(BlueprintCallable)
		UCustomAttackComponent* GetAttackComponent() { return attack; }
	UFUNCTION(BlueprintCallable)
		UCustomMovementComponent* GetMouvementComponent() { return movement; }
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void Init();
	void CheckIsDead();
	void ResetHealth();
public:	
	void AddHealth(const int& _value);
	UFUNCTION(BlueprintCallable)
		int GetHeatlh();
	UFUNCTION(BlueprintCallable)
		int GetMaxHeatlh();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
