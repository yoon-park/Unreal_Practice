// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UE_Project/Global/TestEnum.h"
#include "TestPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UE_PROJECT_API ATestPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATestPlayerController();

	UFUNCTION(BlueprintCallable)
	void ChangeAnimation(ETPSPlayerAnimation _Animation);
};
