// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnFloor.generated.h"

class ABaseLevel;

UCLASS()
class ENDLESSRUNNER_API ASpawnFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnFloor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FString MyString = FString(TEXT("Hello World"));

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	UFUNCTION()
		void SpawnLevel(bool IsFirst);
	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent,AActor* OtherActor,UPrimitiveComponent* OtherComp,int32 OtherBodyIndex,bool bFromSweep,const FHitResult& SweepResult);


protected:
	
	APawn* Player;
	

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> FloorStraight;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> FloorRight;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> FloorLeft;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> FloorDown;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseLevel> FloorUp;

	UPROPERTY(EditAnywhere)
		int TileSpawnAmount;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* StaticMeshComp;





	TArray<ABaseLevel*> LevelList;


public:
	
	FTimerHandle _loopTimerHandle;
	FTimerDelegate LoopTimerHandler;
	int RandomLevel;
	int32 CurrentStraight;
	int32 RandomFloor = 1;
	FVector SpawnLocation = FVector();
	FRotator SpawnRotation = FRotator();
	FTransform Transform = FTransform();
	FActorSpawnParameters SpawnInfo = FActorSpawnParameters();
};
