// Fill out your copyright notice in the Description page of Project Settings.


#include "CorrTrap.h"
#include "PlayerPawn.h"

// Sets default values
ACorrTrap::ACorrTrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	collider = CreateDefaultSubobject<UBoxComponent>("Collision");
	RootComponent = collider;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("mesh");
	mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACorrTrap::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ACorrTrap::OnOverlap);
	settings.SetDamage(10);

}

// Called every frame
void ACorrTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACorrTrap::OnOverlap(AActor* _this, AActor* _other)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap"));
	TObjectPtr<APlayerPawn> _player = Cast<APlayerPawn>(_other);
	if (!_player)return;
	_player->AddHealth(settings.damage);
}

