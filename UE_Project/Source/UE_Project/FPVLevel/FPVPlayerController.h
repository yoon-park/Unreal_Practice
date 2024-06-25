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

	UFUNCTION(BlueprintCallable)
	void MoveFrontCPP(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable)
	void MoveFrontEnd(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable)
	void RotCPP(const FInputActionValue& Value);

	//UFUNCTION(BlueprintCallable)
	//void ChangeAnimation(ETPSPlayerAnimation _Animation);

	//UFUNCTION(BlueprintCallable)
	//void SetupInputComponent() override;

	//UPROPERTY()
	//class UInputActionDatas* InputData;
};
