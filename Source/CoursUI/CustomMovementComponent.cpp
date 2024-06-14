// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomMovementComponent.h"
// Sets default values for this component's properties
UCustomMovementComponent::UCustomMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCustomMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	customOwner = Cast<APawn>(GetOwner());
	customOwner->bUseControllerRotationYaw = true;
	// ...
	
}


// Called every frame
void UCustomMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...
}


void UCustomMovementComponent::Move(const FInputActionValue& _value)
{
	if (!customOwner)return;
	const FVector2D _movementValue = _value.Get<FVector2D>();
	//UE_LOG(LogTemp, Warning, TEXT("Value Y : %f"), _movementValue.Y);
	//UE_LOG(LogTemp, Warning, TEXT("Value X : %f"), _movementValue.X);
	if (_movementValue.Y != 0) {
		const FVector _forwardMovement = customOwner->GetActorLocation() + customOwner->GetActorForwardVector() * _movementValue.Y * moveSpeed * GetWorld()->DeltaTimeSeconds;
		customOwner->SetActorLocation(_forwardMovement);
	}

	if (_movementValue.X != 0) {
		const FVector _rightMovement = customOwner->GetActorLocation() + customOwner->GetActorRightVector() * _movementValue.X * moveSpeed * GetWorld()->DeltaTimeSeconds;
		customOwner->SetActorLocation(_rightMovement);
	}
}


void UCustomMovementComponent::Rotate(const FInputActionValue& _value)
{
	if (!customOwner)return;
	const float _rotateValue = _value.Get<float>();
	customOwner->AddControllerYawInput(_rotateValue * rotationSpeed * GetWorld()->DeltaTimeSeconds);
}
