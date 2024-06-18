// Fill out your copyright notice in the Description page of Project Settings.


#include "CorrTrap.h"
#include "PlayerPawn.h"
#include "PlayGameMode.h"
#include "TrapManager.h"

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
	TObjectPtr<APlayGameMode> _gm = GetWorld()->GetAuthGameMode<APlayGameMode>();
	if (!_gm)return;
	TObjectPtr<ATrapManager> _tm = _gm->GetTrapManager();
	if (!_tm) return;
	_tm->AddElement(this);
	//_allTraps = _tm->GetAllTraps();

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
	_player->AddHealth(-settings.damage);
}

