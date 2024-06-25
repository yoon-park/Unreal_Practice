// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "TestGameInstance.h"
#include "UE_Project/UE_Project.h"

// Sets default values
ATestPlayer::ATestPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->bDoCollisionTest = false;
	SpringArmComponent->TargetArmLength = 800.000000;
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetProjectionMode(ECameraProjectionMode::Perspective);
	CameraComponent->SetupAttachment(SpringArmComponent);

	UEnum* Enum = StaticEnum<EPlayerItemSlot>();
	for (size_t i = 0; i < static_cast<size_t>(EPlayerItemSlot::SlotMax); i++)
	{
		FString Name = Enum->GetNameStringByValue(i);
		UStaticMeshComponent* NewSlotMesh = CreateDefaultSubobject<UStaticMeshComponent>(*Name);
		NewSlotMesh->SetupAttachment(GetMesh(), *Name);

		ItemMeshs.Push(NewSlotMesh);
	}
}

// Called when the game starts or when spawned
void ATestPlayer::BeginPlay()
{
	Super::BeginPlay();
	AnimationContext = Cast<UGlobalAnimInstance>(GetMesh()->GetAnimInstance());
}

// Called every frame
void ATestPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATestPlayer::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ATestPlayer, AniValue);
}

void ATestPlayer::ChangeSlotMesh_Implementation(EPlayerItemSlot _Slot, FName _MeshName)
{
	uint8 SlotIndex = static_cast<uint8>(_Slot);
	if (ItemMeshs.Num() <= SlotIndex)
	{
		//UE_LOG(UE_ProjectLog, Fatal, TEXT("%S(%u)> if (ItemMeshs.Num() <= static_cast<uint8>(_Slot))"), __FUNCTION__, __LINE__);
		return;
	}

	UTestGameInstance* Inst = GetGameInstance<UTestGameInstance>();

	//UStaticMesh* FindMesh = Inst->GetStaticMesh(_MeshName);

	//ItemMeshs[SlotIndex]->SetStaticMesh(FindMesh);
}

void ATestPlayer::ChangeAnimation_Implementation(ETPSPlayerAnimation _Type)
{
	AniValue = _Type;
}