// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "FPVGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UE_PROJECT_API AFPVGameMode : public AGameMode
{
	GENERATED_BODY()
	
	virtual void StartPlay() override;
};
