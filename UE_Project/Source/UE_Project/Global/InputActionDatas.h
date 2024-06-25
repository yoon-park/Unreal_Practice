// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "InputActionDatas.generated.h"

/**
 * 
 */
UCLASS()
class UE_PROJECT_API UInputActionDatas : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UInputActionDatas();
	~UInputActionDatas();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputMappingContext* InputMapping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UInputAction*> Actions;
};
