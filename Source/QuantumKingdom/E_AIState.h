// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EAIState : uint8
{
	// Looking UMETA(DisplayName = "Looking"),
	Chasing UMETA(DisplayName = "Chasing"),
	Fighting UMETA(DisplayName = "Fighting")
};
