#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

#include "BE_AIController.generated.h"

/**
 * 
 */
UCLASS()
class QUANTUMKINGDOM_API ABE_AIController : public AAIController
{
	GENERATED_BODY()
	
public:
	
	// Contructor
	ABE_AIController();
	
protected:
	
	// Event when the AI possesses the pawn
	virtual void OnPossess(APawn* InPawn) override;
	
private:
	
	// Properties
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBehaviorTree* BehaviorTreeAsset;	
	
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UAIPerceptionComponent* PerceptionComp;
	
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UAISenseConfig_Sight* SightConfig;
	
	UFUNCTION()
	void HandlePerception(AActor* Actor, FAIStimulus Stimulus);
};
