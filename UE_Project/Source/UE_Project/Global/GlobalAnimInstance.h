// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TestEnum.h"
#include "GlobalAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UE_PROJECT_API UGlobalAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	template<typename EnumType>
	void ChangeAnimation(const FString& Key)
	{
		ChangeAnimation();
	}

	void ChangeAnimation(const FString& Key);
protected:

	// void Init(TArray<TPair<FString, class UAnimMontage*>>);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TMap < FString, class UAnimMontage* > AnimMontages;
};
