// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyBase.generated.h"

UCLASS()
class QUANTUMKINGDOM_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	int32 MeleeDamage = 1;

	//Distancia ataque
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	//float MeleeRange = 250.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float AttackCooldown = 1.0f;
	float LastAttackTime = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	UAnimMontage* AttackMontage;

	bool bIsAttacking = false;


	UFUNCTION(BlueprintImplementableEvent)
	void EnableWeaponDamage();

	UFUNCTION(BlueprintImplementableEvent)
	void DisableWeaponDamage();

	//void StartAttack();
	void PerformMeleeAttack();
	/*void DoDamageRaycast();*/




};
