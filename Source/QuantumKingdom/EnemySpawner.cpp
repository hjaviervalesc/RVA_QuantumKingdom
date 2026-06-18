// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	timeCount = 0.0f;
	
	SpawnStartDelay == 0.0f ? spawn = true : spawn = false;
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

bool AEnemySpawner::SpawnObjectInLocation(TSubclassOf<AActor> ObjectToSpawn, AActor* SpawnPoint)
{
	// Get the spawn point position and rotation
	FVector spawnLocation = SpawnPoint->GetActorLocation();
	FRotator spawnRotation = SpawnPoint->GetActorRotation();
	
	// Instantiate object as an Actor
	AActor* obj = GetWorld()->SpawnActor<AActor>(SpawnObject, spawnLocation, spawnRotation);
	
	// Return if instantiated correctly
	return obj != nullptr;
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// If the initial delay has passed
	if (spawn)
	{
		// Calculate overall pass of time
		timeCount += DeltaTime;
	
		// If it passes the spawn rate, spawn object
		if (timeCount > SpawnRate)
		{
			// Spawn
			if (SpawnObject != nullptr && SpawnPoints.Num() > 0)
			{
				// Get a random spawn point
				int32 randomIndex = FMath::RandRange(0, SpawnPoints.Num() - 1);
				AActor* spawnPoint = SpawnPoints[randomIndex];
			
				bool isSpawned = SpawnObjectInLocation(SpawnObject, spawnPoint);
			
				if (!isSpawned)
				{
					UE_LOG(LogTemp, Warning, TEXT("WARNING: Couldn't spawn object at location %s!"), *spawnPoint->GetActorLocation().ToString());
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("WARNING: Actor to spawn or spawn locations not available!"))
			}
	
			// Resetear la cuenta
			timeCount -= SpawnRate;
		}
	}
}

