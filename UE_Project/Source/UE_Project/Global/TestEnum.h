// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TestEnum.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class ETPSPlayerAnimation : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	FrontRun UMETA(DisplayName = "FrontRun"),
	BackRun UMETA(DisplayName = "BackRun"),
	LeftRun UMETA(DisplayName = "LeftRun"),
	RightRun UMETA(DisplayName = "RightRun"),
	Jump UMETA(DisplayName = "Jump"),
};

UENUM(BlueprintType)
enum class EPlayerItemSlot : uint8
{
	LWeapon,
	RWeapon,
	SlotMax,
};

UCLASS()
class UE_PROJECT_API UTestEnum : public UObject
{
	GENERATED_BODY()
	
};