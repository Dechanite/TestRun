// Fill out your copyright notice in the Description page of Project Settings.

#include "EndlessRunnerCharacter.h"
#include "Components/SphereComponent.h"
#include "Engine.h"
#include "Coin.h"

// Sets default values
ACoin::ACoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RotationValue = 0;
}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();
	//Coin = GetWorld()->SpawnActor<ACoin>
	//CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ALigthSwitchCodeOnly::OnOverlapBegin);
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorRotation(FRotator(0.0f, RotationValue++, 0.0f));
}

void ACoin::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OverlappedComponent->GetOwner()->SetLifeSpan(4);
}




