// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "EnhancedInputComponent.h" 
#include "EnhancedInputSubsystems.h"
#include "C:/Program Files/Epic Games/UE_5.3/Engine/Plugins/EnhancedInput/Source/EnhancedInput/Public/EnhancedInputComponent.h"
#include "C:/Program Files/Epic Games/UE_5.3/Engine/Plugins/EnhancedInput/Source/EnhancedInput/Public/InputTriggers.h"
#include "C:/Program Files/Epic Games/UE_5.3/Engine/Plugins/EnhancedInput/Source/EnhancedInput/Public/EnhancedInputSubsystems.h"
// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	skeleton = CreateDefaultSubobject<USkeletalMeshComponent>("skeleton");
	springArm = CreateDefaultSubobject<USpringArmComponent>("springArm");
	camera = CreateDefaultSubobject<UCameraComponent>("camera");
	movement = CreateDefaultSubobject<UCustomMovementComponent>("movement");
	attack = CreateDefaultSubobject<UCustomAttackComponent>("attack");

	skeleton->SetupAttachment(RootComponent);
	springArm->SetupAttachment(RootComponent);
	camera->SetupAttachment(springArm);
	AddOwnedComponent(movement);
	AddOwnedComponent(attack);
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CheckIsDead();
}

void APlayerPawn::Init()
{
	TObjectPtr<ULocalPlayer> _localPlayer = GetWorld()->GetFirstPlayerController()->GetLocalPlayer();
	if (!_localPlayer)return;
	TObjectPtr<UEnhancedInputLocalPlayerSubsystem> _sub = _localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if (!_sub)return;
	_sub->AddMappingContext(mappingContext, 0);
	ResetHealth();
}

void APlayerPawn::CheckIsDead()
{
	if (heatlh <= 0) {
		Destroy();
	}
}

void APlayerPawn::ResetHealth()
{
	heatlh = pourcentFull;
	onHeatlhUpdated.Broadcast(heatlh);
}

void APlayerPawn::AddHealth(const int& _value)
{
	heatlh += _value;
	heatlh = heatlh < 0 ? 0 : heatlh;
	onHeatlhUpdated.Broadcast(heatlh);
}

int APlayerPawn::GetHeatlh()
{
	if (pourcentFull == 0)
	{
		return 0.0f;
	}

	return heatlh / pourcentFull;
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	TObjectPtr<UEnhancedInputComponent> _inputCompo = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!_inputCompo)return;
	_inputCompo->BindAction(moveInput, ETriggerEvent::Triggered,movement.Get(), &UCustomMovementComponent::Move);
	_inputCompo->BindAction(moveInput, ETriggerEvent::Completed,movement.Get(), &UCustomMovementComponent::Move);
	_inputCompo->BindAction(rotateInput, ETriggerEvent::Triggered, movement.Get(), &UCustomMovementComponent::Rotate);
	_inputCompo->BindAction(fireInput, ETriggerEvent::Started, attack.Get(), &UCustomAttackComponent::Attack);
	_inputCompo->BindAction(reloadInput, ETriggerEvent::Started, attack.Get(), &UCustomAttackComponent::Reload);
}

