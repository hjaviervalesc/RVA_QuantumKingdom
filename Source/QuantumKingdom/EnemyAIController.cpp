// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"

void AEnemyAIController::BeginPlay()
{
    Super::BeginPlay();
}

void AEnemyAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (Player)
    {
        MoveToActor(Player, 5.0f);
    }
}


