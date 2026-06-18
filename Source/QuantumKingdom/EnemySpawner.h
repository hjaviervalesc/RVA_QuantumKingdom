// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class QUANTUMKINGDOM_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	
	float timeCount;
	bool spawn;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called to spawn an object in a certain location
	bool SpawnObjectInLocation(TSubclassOf<AActor> ObjectToSpawn, AActor* SpawnPoint);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Spawn start delay if any
	UPROPERTY(EditAnywhere, Category="Spawner Settings")
	float SpawnStartDelay;
	
	// Time between spawns
	UPROPERTY(EditAnywhere, Category="Spawner Settings")
	float SpawnRate;
	
	// Object template to spawn
	UPROPERTY(EditAnywhere, Category="Spawner Settings")
	TSubclassOf<AActor> SpawnObject;
	
	// Spawn points where the objects will appear
	UPROPERTY(EditAnywhere, Category="Spawner Settings")
	TArray<AActor*> SpawnPoints;
};
