// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterEditorPawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "Pawns/ChildPawnSK.h"
#include "UI/WPawnEditor.h"

#include "Kismet/GameplayStatics.h"

#include "Runtime/UMG/Public/UMG.h"

// Sets default values
ACharacterEditorPawn::ACharacterEditorPawn(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UWPawnEditor> 
		PawnEditorObject(TEXT("Class'/Script/UIExample.WPawnEditor'"));

	if (PawnEditorObject.Succeeded())
		PawnEditorUIClass = PawnEditorObject.Class;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = ZoomNormal;
	FRotator SpringArmRotation;
	SpringArmRotation.Pitch = -20.0f;
	SpringArm->SetRelativeRotation(SpringArmRotation);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacterEditorPawn::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(0.0f, 0.0f, 105.0f));
	SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));

	APlayerController* Player = GetWorld()->GetFirstPlayerController();
	Player->bShowMouseCursor = true;
	Player->bEnableClickEvents = true;
	Player->bEnableMouseOverEvents = true;

	if (!PawnEditorUI)
	{
		PawnEditorUI = CreateWidget<UWPawnEditor>(Player, PawnEditorUIClass);
		if (PawnEditorUI)
		{
			PawnEditorUI->AddToViewport(0);
			PawnEditorUI->OnSkeletalMeshChanged.AddDynamic(this, &ACharacterEditorPawn::UpdateCharacter);
			PawnEditorUI->OnRotation.AddDynamic(this, &ACharacterEditorPawn::SetRotationRate);
			PawnEditorUI->OnHairChanged.AddDynamic(this, &ACharacterEditorPawn::UpdateCharacterHair);
		}

	}

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
	SpawnRotation.Yaw = DefaultCharacterYaw;
	CharacterSK = GetWorld()->SpawnActor<AChildPawnSK>(AChildPawnSK::StaticClass(), DefaultCharacterPosition, SpawnRotation, Params);
	
}

// Called every frame
void ACharacterEditorPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateRotation(DeltaTime);
	UpdateZoom(DeltaTime);

}

void ACharacterEditorPawn::UpdateRotation(float Delta)
{
	if (RotationDirection == 0.0f || CharacterSK == nullptr)
	{
		return;
	}

	float Speed = RotationRate * (RotationDirection * Delta);
	FRotator Rotation = CharacterSK->GetActorRotation();
	Rotation.Yaw += Speed;
	CharacterSK->SetActorRelativeRotation(Rotation);

	FString Printer = FString::SanitizeFloat(Rotation.Yaw);

	//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Yellow, Printer);
}

void ACharacterEditorPawn::UpdateZoom(float Delta)
{
	if (ZoomValue == 0.0f)
	{
		return;
	}

	float Position = SpringArm->TargetArmLength;

	if ( (ZoomValue > 0.0f && Position > ZoomOutMax)
	|| (ZoomValue < 0.0f && Position < ZoomInMax) )
	{
		ZoomValue = 0.0f;
		return;
	}

	float Speed = ZoomSpeed * (ZoomValue * Delta);
	Position += Speed;
	SpringArm->TargetArmLength = Position;

}

void ACharacterEditorPawn::SetRotationRate(float Value)
{
	RotationDirection = Value;
}

void ACharacterEditorPawn::SetZoomDirection(float InDirection, bool bReset)
{
	if (bReset)
	{
		ZoomValue = 0.0f;
		SpringArm->TargetArmLength = ZoomNormal;
	}
}

void ACharacterEditorPawn::UpdateCharacterHair(USkeletalMesh* Hair)
{
	UpdateCharacter(Hair, 1);
}

void ACharacterEditorPawn::UpdateCharacter(USkeletalMesh* InSkeletalMesh, int CategoryIndex)
{
	if (CharacterSK == nullptr)
	{
		return;
	}
	CharacterSK->UpdateSkeletalMeshes(InSkeletalMesh, CategoryIndex);
}

// Called to bind functionality to input
void ACharacterEditorPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

