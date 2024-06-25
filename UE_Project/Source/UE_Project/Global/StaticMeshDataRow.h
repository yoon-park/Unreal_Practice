// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "StaticMeshDataRow.generated.h"


USTRUCT(BlueprintType)
struct FStaticMeshDataRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	FStaticMeshDataRow();
	~FStaticMeshDataRow();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
	UStaticMesh* StaticMesh;
};
