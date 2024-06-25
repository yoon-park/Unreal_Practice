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

	//	// 유효한 리소스냐를 판단할수 있습니다.
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

	// 블루프린트에 있는 변수값을 어떻게 바꿀건가요?

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
//	// 여기에서 로드해야 한다.
//	// 문제가 한가지 있다.
//	// 플레이가 된 시점입니다.
//	// 그때 로드가 안되는 녀석들이 많다.
//	{
//		UEnhancedInputLocalPlayerSubsystem* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
//
//		// protected는 자신의 input 컴포넌트 자체를 가지고 있다.
//		UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
//
//		// 모든 컨텍스트를 다 날리는 기능.
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
