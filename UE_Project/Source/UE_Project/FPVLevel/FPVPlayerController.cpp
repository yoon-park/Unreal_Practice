// Fill out your copyright notice in the Description page of Project Settings.

#include "FPVPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedActionKeyMapping.h"
#include "InputMappingContext.h"
#include "InputAction.h"

#include "UE_Project/Global/InputActionDatas.h"
#include "FPVCharacter.h"

AFPVPlayerController::AFPVPlayerController()
{
	{
		FString RefPathString = TEXT("InputActionDatas'/Game/Resources/FPVLevel/Data/FPVInputDataAsset.FPVInputDataAsset'");
		ConstructorHelpers::FObjectFinder<UInputActionDatas> ResPath(*RefPathString);

		if (false == ResPath.Succeeded())
		{
			return;
		}

		InputData = ResPath.Object;
	} 
}

void AFPVPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
	
	{
		UEnhancedInputLocalPlayerSubsystem* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
		UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);

		InputSystem->ClearAllMappings();
		InputSystem->AddMappingContext(InputData->InputMapping, 0);

		if (nullptr != InputData->InputMapping)
		{
			EnhancedInputComponent->BindAction(InputData->Actions[0], ETriggerEvent::Triggered, this, &AFPVPlayerController::MouseRotation);
			EnhancedInputComponent->BindAction(InputData->Actions[1], ETriggerEvent::Triggered, this, &AFPVPlayerController::MoveFront);
			EnhancedInputComponent->BindAction(InputData->Actions[1], ETriggerEvent::Completed, this, &AFPVPlayerController::MoveFrontEnd);
			EnhancedInputComponent->BindAction(InputData->Actions[5], ETriggerEvent::Triggered, this, &AFPVPlayerController::Jump);
			EnhancedInputComponent->BindAction(InputData->Actions[5], ETriggerEvent::Completed, this, &AFPVPlayerController::JumpEnd);
		}
	}
}

void AFPVPlayerController::MouseRotation(const FInputActionValue& Value)
{
	FVector2D MouseXY = Value.Get<FVector2D>();
	AddYawInput(MouseXY.X);
	AddPitchInput(-MouseXY.Y);
}

void AFPVPlayerController::MoveFront(const FInputActionValue& Value)
{
	//ChangeAnimation(ETPSPlayerAnimation::Run);
	FVector Forward = GetPawn()->GetActorForwardVector();
	GetPawn()->AddMovementInput(Forward);
}

void AFPVPlayerController::MoveFrontEnd(const FInputActionValue& Value)
{
	//ChangeAnimation(ETPSPlayerAnimation::Idle);
}

void AFPVPlayerController::Jump(const FInputActionValue& Value)
{
	//ChangeAnimation(ETPSPlayerAnimation::Jump);
	AFPVCharacter* Ch = GetPawn<AFPVCharacter>();
	Ch->Jump();
}

void AFPVPlayerController::JumpEnd(const FInputActionValue& Value)
{
	//ChangeAnimation(ETPSPlayerAnimation::Idle);
	AFPVCharacter* Ch = GetPawn<AFPVCharacter>();
	Ch->StopJumping();
}

//void AFPVPlayerController::ChangeAnimation(ETPSPlayerAnimation _Animation)
//{
//	ATPSPlayCharacter* Ch = GetPawn<ATPSPlayCharacter>();
//	Ch->ChangeAnimation(_Animation);
//}