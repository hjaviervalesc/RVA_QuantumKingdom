// Fill out your copyright notice in the Description page of Project Settings.


#include "BE_AIController.h"

ABE_AIController::ABE_AIController()
{
	PerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>("PerceptionComp");
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>("SightConfig");
	
	SightConfig->SightRadius = 1500.0f;
	SightConfig->LoseSightRadius = 1800.0f;
	SightConfig->PeripheralVisionAngleDegrees = 60.0f;
	
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	// SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	// SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	
	PerceptionComp->ConfigureSense(*SightConfig);
	PerceptionComp->SetDominantSense(SightConfig->GetSenseImplementation());
	
	PerceptionComp->OnTargetPerceptionUpdated.AddDynamic(this, &ABE_AIController::HandlePerception);
}

void ABE_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	
	if (BehaviorTreeAsset != nullptr)
	{
		RunBehaviorTree(BehaviorTreeAsset);
	}
}

void ABE_AIController::HandlePerception(AActor* Actor, FAIStimulus Stimulus)
{
	if (Stimulus.WasSuccessfullySensed())
	{
		UE_LOG(LogTemp, Warning, TEXT("SightConfig_Sight Sensed"));
	}
}
