// Fill out your copyright notice in the Description page of Project Settings.


#include "TestGameInstance.h"
#include "UE_Project/Global/StaticMeshDataRow.h"
#include "UE_Project/UE_Project.h"

UTestGameInstance::UTestGameInstance()
{

}

UStaticMesh* UTestGameInstance::GetStaticMesh(FName _Name)
{
	if (nullptr == GlobalStaticMeshTable)
	{
		//UE_LOG(GIMATLog, Fatal, TEXT("%S(%u)> if (nullptr == MonsterDataTable)"), __FUNCTION__, __LINE__);
	}

	FStaticMeshDataRow* Data = GlobalStaticMeshTable->FindRow<FStaticMeshDataRow>(_Name, nullptr);

	if (nullptr == Data)
	{
		//UE_LOG(GIMATLog, Error, TEXT("%S(%u)> %s Name Data Is Nullptr"), __FUNCTION__, __LINE__, *_Name.ToString());
		return nullptr;
	}

	return Data->StaticMesh;
}