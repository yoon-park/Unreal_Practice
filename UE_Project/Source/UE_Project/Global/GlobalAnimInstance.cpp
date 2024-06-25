// Fill out your copyright notice in the Description page of Project Settings.


#include "GlobalAnimInstance.h"
#include "UE_Project/UE_Project.h"

void UGlobalAnimInstance::ChangeAnimation(const FString& Key)
{
	if (false == AnimMontages.Contains(Key))
	{
		//UE_LOG(UE_ProjectLog, Fatal, TEXT("%S(%u)> if (false == AnimMontages.Contains(Key))"), __FUNCTION__, __LINE__);
		return;
	}

	UAnimMontage* Mon = AnimMontages[Key];

	if (nullptr == Mon)
	{
		//UE_LOG(UE_ProjectLog, Fatal, TEXT("%S(%u)> if (nullptr == Mon)"), __FUNCTION__, __LINE__);
		return;
	}

	Montage_Play(Mon);
}