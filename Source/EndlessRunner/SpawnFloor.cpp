// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnFloor.h"

#include "BaseLevel.h"
#include "Engine.h"
#include "Components/BoxComponent.h"
#include "EndlessRunnerCharacter.h"
#include <chrono>
#include <thread>
// Sets default values
ASpawnFloor::ASpawnFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnFloor::BeginPlay()
{
	Super::BeginPlay();

	SpawnLevel(true);
	for (int i = 0; i < TileSpawnAmount; i++)
	{
		SpawnLevel(false);
	}

}

// Called every frame
void ASpawnFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnFloor::SpawnLevel(bool IsFirst)
{
	SpawnLocation = FVector(0.0f, 0.0f, 0.0f);
	SpawnRotation = FRotator(0, 90, 0);


	if (!IsFirst)
	{
		ABaseLevel* LastLevel = LevelList[0];

		SpawnLocation = LastLevel->GetSpawnLocation()->GetComponentTransform().GetTranslation();
		SpawnRotation = LastLevel->GetSpawnRotation()->GetComponentRotation();
		Transform = LastLevel->GetSpawnRotation()->GetComponentTransform();
		
	}

	RandomLevel = FMath::RandRange(1, RandomFloor);
	ABaseLevel* NewLevel = nullptr;
	if (RandomLevel == 1 || RandomLevel == 2 || RandomLevel == 3 || RandomLevel == 4)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(FloorStraight, SpawnLocation, SpawnRotation, SpawnInfo);
		if (GEngine)
		{
			CurrentStraight += 1;
			GEngine->AddOnScreenDebugMessage(-10, 1.f, FColor::Yellow, FString::Printf(TEXT("Rotation: %i"), CurrentStraight));
			if (CurrentStraight >= 15)
			{
				CurrentStraight = FMath::RandRange(5,  15);
				RandomFloor = 8;
			}
		}

	}
	else if (RandomLevel == 5)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(FloorRight, SpawnLocation, SpawnRotation, SpawnInfo);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-10, 1.f, FColor::Yellow, FString::Printf(TEXT("Rotation: %i"), 1));
			RandomFloor = 1;
		}


	}

	else if (RandomLevel == 6)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(FloorLeft, SpawnLocation, SpawnRotation, SpawnInfo);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-10, 1.f, FColor::Yellow, FString::Printf(TEXT("Rotation: %i"), 1));
			RandomFloor = 1;
		}

	}

	else if (RandomLevel == 7)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(FloorDown, SpawnLocation, SpawnRotation, SpawnInfo);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-10, 1.f, FColor::Yellow, FString::Printf(TEXT("Rotation: %i"), 1));
			RandomFloor = 1;
		}

	}

	else if (RandomLevel == 8)
	{
		NewLevel = GetWorld()->SpawnActor<ABaseLevel>(FloorUp, SpawnLocation, SpawnRotation, SpawnInfo);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-10, 1.f, FColor::Yellow, FString::Printf(TEXT("Rotation: %i"), 1));
			RandomFloor = 1;
		}

	}

	if (NewLevel)
	{
		if (NewLevel->GetTrigger())
		{
			NewLevel->GetTrigger()->OnComponentBeginOverlap.
				AddDynamic(this, &ASpawnFloor::BeginOverlap);
			
		}
	}


	LevelList.Insert(NewLevel, 0);
	
	
}

void ASpawnFloor::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->IsA(AEndlessRunnerCharacter::StaticClass()))
	{

		SpawnLevel(false);
		//OverlappedComponent->DestroyComponent();
		OverlappedComponent->GetOwner()->SetLifeSpan(4);
	}
	
	
}



