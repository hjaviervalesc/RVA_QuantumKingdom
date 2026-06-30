// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyBase.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyAIController.h"
#include "Components/AudioComponent.h"

AEnemyBase::AEnemyBase()
{
    PrimaryActorTick.bCanEverTick = true;

    AIControllerClass = AEnemyAIController::StaticClass();
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
    // --- AUDIO ---
    FootstepsAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("FootstepsAudio"));
    FootstepsAudio->SetupAttachment(RootComponent);
    FootstepsAudio->bAutoActivate = false;

    AttackAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("AttackAudio"));
    AttackAudio->SetupAttachment(RootComponent);
    AttackAudio->bAutoActivate = false;
}
void AEnemyBase::PlayFootsteps()
{
    if (FootstepsAudio && !FootstepsAudio->IsPlaying())
    {
        FootstepsAudio->Play();
    }
}

void AEnemyBase::StopFootsteps()
{
    if (FootstepsAudio && FootstepsAudio->IsPlaying())
    {
        FootstepsAudio->Stop();
    }
}

void AEnemyBase::PerformMeleeAttack()
{
    float CurrentTime = GetWorld()->GetTimeSeconds();

    if (CurrentTime - LastAttackTime < AttackCooldown || bIsAttacking)
        return;

    LastAttackTime = CurrentTime;
    bIsAttacking = true;

    if (AttackMontage)
    {
        PlayAnimMontage(AttackMontage);
    }
    if (AttackAudio)
    {
        AttackAudio->Play();
    }
    // ACTIVAR DAÑO
    EnableWeaponDamage();

    FTimerHandle ResetHandle;
    GetWorld()->GetTimerManager().SetTimer(
        ResetHandle,
        [this]()
        {
            bIsAttacking = false;

            // DESACTIVAR DAÑO
            DisableWeaponDamage();
        },
        2.2f,
        false
    );
}

//AEnemyBase::AEnemyBase()
//{
//    PrimaryActorTick.bCanEverTick = true;
//
//    AIControllerClass = AEnemyAIController::StaticClass();
//    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
//}
//void AEnemyBase::PerformMeleeAttack()
//{
//    // Cooldown
//    float CurrentTime = GetWorld()->GetTimeSeconds();
//    if (CurrentTime - LastAttackTime < AttackCooldown || bIsAttacking)
//        return;
//
//    LastAttackTime = CurrentTime;
//    bIsAttacking = true;
//
//    // Reproducir animación
//    if (AttackMontage)
//    {
//        PlayAnimMontage(AttackMontage);
//    }
//
//    // Lanzar el ataque real después de un pequeño delay
//    // (para sincronizar con el golpe de la animación)
//    FTimerHandle TimerHandle;
//    GetWorld()->GetTimerManager().SetTimer(
//        TimerHandle,
//        this,
//        &AEnemyBase::DoDamageRaycast,
//        0.92f,   // tiempo hasta el impacto (ajústalo según la animación)
//        false
//    );
//
//    // Resetear estado de ataque al terminar la animación
//    FTimerHandle ResetHandle;
//    GetWorld()->GetTimerManager().SetTimer(
//        ResetHandle,
//        [this]()
//        {
//            bIsAttacking = false;
//        },
//        2.4f,   // duración de la animación
//        false
//    );
//}
//
////void AEnemyBase::DoDamageRaycast()
////{
////    
////    DrawDebugSphere(GetWorld(), GetActorLocation(), 20, 12, FColor::Blue, false, 0.1f);
////    APawn* Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
////    if (!Player) return;
////
////    FVector Start = GetActorLocation() + FVector(0, 0, 80);
////    FVector Forward = GetActorForwardVector();
////    FVector End = Start + Forward * MeleeRange;
////
////    FHitResult Hit;
////    FCollisionQueryParams Params;
////    Params.AddIgnoredActor(this);
////
////    bool bHit = GetWorld()->LineTraceSingleByChannel(
////        Hit,
////        Start,
////        End,
////        ECC_Visibility,
////        Params
////    );
////
////    DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 0.2f, 0, 2.0f);
////
////    if (bHit && Hit.GetActor())
////    {
////        UE_LOG(LogTemp, Warning, TEXT("HIT: %s"), *Hit.GetActor()->GetName());
////
////        UGameplayStatics::ApplyDamage(
////            Hit.GetActor(),
////            MeleeDamage,
////            GetController(),
////            this,
////            nullptr
////        );
////    }
////}
//
//
