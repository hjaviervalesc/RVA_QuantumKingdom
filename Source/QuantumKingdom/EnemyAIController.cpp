// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyBase.h"


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
        MoveToActor(Player, 100.0f);

        float Distance = FVector::Dist(GetPawn()->GetActorLocation(), Player->GetActorLocation());
        UE_LOG(LogTemp, Warning, TEXT("DISTANCIA: %f"), Distance);

        if (Distance < 250.0f)
        {
            AEnemyBase* Enemy = Cast<AEnemyBase>(GetPawn());
            if (Enemy)
            {
                Enemy->PerformMeleeAttack();
            }
        }
        else
        {
            AEnemyBase* Enemy = Cast<AEnemyBase>(GetPawn());
            if (Enemy)
            {
                Enemy->PlayFootsteps();
            }
        }
    }
}