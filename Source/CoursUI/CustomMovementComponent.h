// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InputMappingContext.h"
#include "CustomMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COURSUI_API UCustomMovementComponent : public UActorComponent
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
			float moveSpeed = 600;
		UPROPERTY(EditAnywhere)
			TObjectPtr<APawn> customOwner= nullptr;
		UPROPERTY(EditAnywhere)
			float rotationSpeed = 200;
		UPROPERTY(EditAnywhere)
			float rightMovement = 0;
		UPROPERTY(EditAnywhere)
			float forwardMovement = 0;
public:	
	// Sets default values for this component's properties
	UCustomMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
		float GetRightMovement() const { return rightMovement; }
	UFUNCTION(BlueprintCallable)
		float GetForwardMovement() const { return forwardMovement; }

public:	
	void Move(const FInputActionValue& _value);
	void Rotate(const FInputActionValue& _value);
		
};
