// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPlayerController.h"
#include "TestPlayer.h"

ATestPlayerController::ATestPlayerController()
{

}

void ATestPlayerController::ChangeAnimation(ETPSPlayerAnimation _Animation)
{
	ATestPlayer* Ch = GetPawn<ATestPlayer>();
	Ch->ChangeAnimation(_Animation);
}