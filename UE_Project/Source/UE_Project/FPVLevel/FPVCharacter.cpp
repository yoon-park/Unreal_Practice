// Fill out your copyright notice in the Description page of Project Settings.


#include "FPVCharacter.h"

// Sets default values
AFPVCharacter::AFPVCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFPVCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (GEngine)
	{
		// 5 �ʰ� ����� �޽����� ǥ���մϴ�. (ù �μ���) -1 "Key" ���� �� �޽����� ������Ʈ �Ǵ� ���ΰ�ĥ �ʿ䰡 ������ ��Ÿ���ϴ�.
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using FPVCharacter."));
	}
}

// Called every frame
void AFPVCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPVCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

