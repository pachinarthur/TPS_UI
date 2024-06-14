// Fill out your copyright notice in the Description page of Project Settings.


#include "Trap.h"
#include "PlayerPawn.h"

void ATrap::BeginPlay()
{
	Super::BeginPlay();
	//OnActorBeginOverlap.AddDynamic(this, &ATrap::OnOverlapBegin);
	UE_LOG(LogTemp, Warning, TEXT("tata"));
}

void ATrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawDebugBox(GetWorld(), GetActorLocation(), FVector(200, 200, 200), FColor::Green, false, -1.0f, 2,2);
}

ATrap::ATrap()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATrap::OnOverlapBegin(AActor* _overlapped, AActor* _overlap)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap"));
	APlayerPawn* _entity = Cast<APlayerPawn>(_overlap);
	_entity->AddHealth(-degats);

}
