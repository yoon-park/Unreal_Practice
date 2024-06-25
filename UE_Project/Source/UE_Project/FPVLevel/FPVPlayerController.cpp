// Fill out your copyright notice in the Description page of Project Settings.


#include "FPVPlayerController.h"
#include "FPVCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedActionKeyMapping.h"
#include "InputMappingContext.h"
//#include "Global/DataAssets/InputActionDatas.h"
#include "InputAction.h"

AFPVPlayerController::AFPVPlayerController()
{
	//{
	//	// / Script / GIMAT.InputActionDatas'/Game/Resources/TPS/Datas/InputAction.InputAction'

	//	FString RefPathString = TEXT("InputActionDatas'/Game/Resources/TPS/Datas/InputAction.InputAction'");

	//	ConstructorHelpers::FObjectFinder<UInputActionDatas> ResPath(*RefPathString);

	//	// ��ȿ�� ���ҽ��ĸ� �Ǵ��Ҽ� �ֽ��ϴ�.
	//	if (false == ResPath.Succeeded())
	//	{
	//		return;
	//	}

	//	InputData = ResPath.Object;
	//}
}

//void AFPVPlayerController::ChangeAnimation(ETPSPlayerAnimation _Animation)
//{
//	ATPSPlayCharacter* Ch = GetPawn<ATPSPlayCharacter>();
//	Ch->ChangeAnimation(_Animation);
//}

void AFPVPlayerController::MoveFrontCPP(const FInputActionValue& Value)
{
	//ChangeAnimation(ETPSPlayerAnimation::Run);

	// �������Ʈ�� �ִ� �������� ��� �ٲܰǰ���?

	// AniValue = ETPSPlayerAnimation::Run;

	FVector Forward = GetPawn()->GetActorForwardVector();
	GetPawn()->AddMovementInput(Forward);
}

void AFPVPlayerController::MoveFrontEnd(const FInputActionValue& Value)
{
	//ChangeAnimation(ETPSPlayerAnimation::Idle);
	// AniValue = ETPSPlayerAnimation::Idle;
}

void AFPVPlayerController::RotCPP(const FInputActionValue& Value)
{
	FVector2D MouseXY = Value.Get<FVector2D>();
	AddYawInput(MouseXY.X);
}
//
//void AFPVPlayerController::SetupInputComponent()
//{
//	Super::SetupInputComponent();
//
//	FInputModeGameOnly InputMode;
//	SetInputMode(InputMode);
//	// SetInputMode()
//
//	// ���⿡�� �ε��ؾ� �Ѵ�.
//	// ������ �Ѱ��� �ִ�.
//	// �÷��̰� �� �����Դϴ�.
//	// �׶� �ε尡 �ȵǴ� �༮���� ����.
//	{
//		UEnhancedInputLocalPlayerSubsystem* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
//
//		// protected�� �ڽ��� input ������Ʈ ��ü�� ������ �ִ�.
//		UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
//
//		// ��� ���ؽ�Ʈ�� �� ������ ���.
//		InputSystem->ClearAllMappings();
//		InputSystem->AddMappingContext(InputData->InputMapping, 0);
//
//		if (nullptr != InputData->InputMapping)
//		{
//			EnhancedInputComponent->BindAction(InputData->Actions[0], ETriggerEvent::Triggered, this, &AFPVPlayerController::MoveFrontCPP);
//
//			EnhancedInputComponent->BindAction(InputData->Actions[0], ETriggerEvent::Completed, this, &AFPVPlayerController::MoveFrontEnd);
//
//			EnhancedInputComponent->BindAction(InputData->Actions[1], ETriggerEvent::Triggered, this, &AFPVPlayerController::RotCPP);
//		}
//	}
//
//
//}
