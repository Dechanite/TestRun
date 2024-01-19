// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorSpawner.h"
#include "Components/BoxComponent.h"
#include "ActorToSpawn.h"

// Sets default values
AActorSpawner::AActorSpawner()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
    SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolume"));

    SpawnVolume->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AActorSpawner::BeginPlay()
{
    Super::BeginPlay();
}

void AActorSpawner::SpawnActor()
{
    FVector SpawnLocation = GetActorLocation();
    FRotator SpawnRotation = GetActorRotation();
    GetWorld()->SpawnActor<AActorToSpawn>(SpawnLocation, SpawnRotation);
}

// Called every frame
void AActorSpawner::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

