// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FPVPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UE_PROJECT_API AFPVPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AFPVPlayerController();

	// Input
	UPROPERTY()
	class UInputActionDatas* InputData;

	UFUNCTION(BlueprintCallable)
	void SetupInputComponent() override;

	// Actions
	UFUNCTION(BlueprintCallable)
	void MouseRotation(const FInputActionValue& Value);
	UFUNCTION(BlueprintCallable)
	void MoveFront(const FInputActionValue& Value);
	UFUNCTION(BlueprintCallable)
	void MoveFrontEnd(const FInputActionValue& Value);
	UFUNCTION(BlueprintCallable)
	void Jump(const FInputActionValue& Value);
	UFUNCTION(BlueprintCallable)
	void JumpEnd(const FInputActionValue& Value);

	// Animation
	//UFUNCTION(BlueprintCallable)
	//void ChangeAnimation(ETPSPlayerAnimation _Animation);
};
