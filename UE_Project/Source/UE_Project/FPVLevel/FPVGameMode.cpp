// Fill out your copyright notice in the Description page of Project Settings.


#include "FPVGameMode.h"

void AFPVGameMode::StartPlay()
{
    Super::StartPlay();

    if (GEngine)
    {
        // ����� �޽����� 5 �ʰ� ǥ���մϴ�.
        // "Ű" (ù ��° �μ�) ���� -1 �� �ϸ� �� �޽����� ���� ������Ʈ�ϰų� ���ΰ�ĥ �ʿ䰡 ������ ��Ÿ���ϴ�.
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is FPVGameMode!"));
    }
}