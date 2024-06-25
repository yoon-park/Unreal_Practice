// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TestGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UE_PROJECT_API UTestGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UStaticMesh* GetStaticMesh(FName _Name);

private:
	UTestGameInstance();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UDataTable* GlobalStaticMeshTable;
};
