// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyBase.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyAIController.h"

AEnemyBase::AEnemyBase()
{
    PrimaryActorTick.bCanEverTick = true;

    AIControllerClass = AEnemyAIController::StaticClass();
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}
void AEnemyBase::PerformMeleeAttack()
{
    // Cooldown del ataque
    float CurrentTime = GetWorld()->GetTimeSeconds();
    if (CurrentTime - LastAttackTime < AttackCooldown)
    {
        return; // demasiado pronto para atacar otra vez
    }

    // Actualizamos el tiempo del último ataque
    LastAttackTime = CurrentTime;

    //Obtengo al jugador
    APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if (!Player) return;

    // 2. Calcular desde dónde y hacia dónde golpeamos
    FVector Start = GetActorLocation();
    FVector Forward = GetActorForwardVector();
    FVector End = Start + Forward * MeleeRange;

    // 3. Preparar el raycast
    FHitResult Hit;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this);

    // 4. Lanzar el rayo
    bool bHit = GetWorld()->LineTraceSingleByChannel(
        Hit,
        Start,
        End,
        ECC_Pawn,
        Params
    );

    // Debug para ver el rayo
    DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 0.2f, 0, 2.0f);

    // 5. Si golpeamos algo → aplicar daño
    if (bHit && Hit.GetActor())
    {
        UE_LOG(LogTemp, Warning, TEXT("HIT: %s"), *Hit.GetActor()->GetName());
        UGameplayStatics::ApplyDamage(
            Hit.GetActor(),
            MeleeDamage,      // 1 corazón
            GetController(),
            this,
            nullptr
        );
    }
}



