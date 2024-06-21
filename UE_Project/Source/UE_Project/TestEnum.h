// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TestEnum.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EPlayerAnimation : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	Run UMETA(DisplayName = "Run"),
};

UCLASS()
class UE_PROJECT_API UTestEnum : public UObject
{
	GENERATED_BODY()
	
};