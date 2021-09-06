// Fill out your copyright notice in the Description page of Project Settings.


#include "ChildPawnSK.h"
#include "UObject/ConstructorHelpers.h"


// Sets default values
AChildPawnSK::AChildPawnSK(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	/*	TextCategories.Add( TEXT("Body") );
TextCategories.Add( TEXT("Hair") );
TextCategories.Add( TEXT("Face") );
TextCategories.Add( TEXT("HeadGear") );
TextCategories.Add( TEXT("Shoulders") );
TextCategories.Add( TEXT("Shoes") );
TextCategories.Add( TEXT("Gloves") );*/

	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		BodyObject(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Cloth01SK.Cloth01SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		HairObject(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Hair01SK.Hair01SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		FaceObject(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Face01SK.Face01SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		HeadGearObject(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Hat01SK.Hat01SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		ShoulderObject(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/ShoulderPad01SK.ShoulderPad01SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		ShoeObject(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Shoe01SK.Shoe01SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		GloveObject(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Glove01SK.Glove01SK"));

	static ConstructorHelpers::FObjectFinder<UAnimSequence>
		AnimationObject(TEXT("/Game/ModularRPGHeroesPolyart/Animations/NoWeaponStance/StandingIdle_noWeaponAnim.StandingIdle_noWeaponAnim"));

	if (BodyObject.Succeeded())
		DefaultBody = BodyObject.Object;
	if (HairObject.Succeeded())
		DefaultHair = HairObject.Object;
	if (FaceObject.Succeeded())
		DefaultFace = FaceObject.Object;
	if (HeadGearObject.Succeeded())
		DefaultHead = HeadGearObject.Object;
	if (ShoulderObject.Succeeded())
		DefaultShoulder = ShoulderObject.Object;
	if (ShoeObject.Succeeded())
		DefaultShoe = ShoeObject.Object;
	if (GloveObject.Succeeded())
		DefaultGlove = GloveObject.Object;

	if (AnimationObject.Succeeded())
		DefaultAnimation = AnimationObject.Object;

	BodySK = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BodySK"));
	RootComponent = BodySK;
	BodySK->SetAnimationMode(EAnimationMode::AnimationSingleNode);
	if (IsValid(DefaultBody))
		BodySK->SkeletalMesh = DefaultBody;
	
	HairSK = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HairSK"));
	HairSK->SetupAttachment(RootComponent);
	HairSK->SetAnimationMode(EAnimationMode::AnimationSingleNode);
	if (IsValid(DefaultHair))
		HairSK->SkeletalMesh = DefaultHair;

	FaceSK = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FaceSK"));
	FaceSK->SetupAttachment(RootComponent);
	FaceSK->SetAnimationMode(EAnimationMode::AnimationSingleNode);
	if (IsValid(DefaultFace))
		FaceSK->SkeletalMesh = DefaultFace;

	HeadGearSK = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("HeadGearSK"));
	HeadGearSK->SetupAttachment(RootComponent);
	HeadGearSK->SetVisibility(false);
	HeadGearSK->SetAnimationMode(EAnimationMode::AnimationSingleNode);
	if (IsValid(DefaultHead))
		HeadGearSK->SkeletalMesh = DefaultHead;

	ShoulderSK = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ShoulderSK"));
	ShoulderSK->SetupAttachment(RootComponent);
	ShoulderSK->SetVisibility(false);
	ShoulderSK->SetAnimationMode(EAnimationMode::AnimationSingleNode);
	if (IsValid(DefaultShoulder))
		ShoulderSK->SkeletalMesh = DefaultShoulder;

	ShoeSK = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ShoeSK"));
	ShoeSK->SetupAttachment(RootComponent);
	ShoeSK->SetAnimationMode(EAnimationMode::AnimationSingleNode);
	if (IsValid(DefaultShoe))
		ShoeSK->SkeletalMesh = DefaultShoe;

	GloveSK = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("GloveSK"));
	GloveSK->SetupAttachment(RootComponent);
	GloveSK->SetAnimationMode(EAnimationMode::AnimationSingleNode);
	if (IsValid(DefaultGlove))
		GloveSK->SkeletalMesh = DefaultGlove;

	if (IsValid(DefaultAnimation))
	{
		BodySK->OverrideAnimationData(DefaultAnimation);
		HairSK->OverrideAnimationData(DefaultAnimation);
		FaceSK->OverrideAnimationData(DefaultAnimation);
		HeadGearSK->OverrideAnimationData(DefaultAnimation);
		ShoulderSK->OverrideAnimationData(DefaultAnimation);
		ShoeSK->OverrideAnimationData(DefaultAnimation);
		GloveSK->OverrideAnimationData(DefaultAnimation);
	}





 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChildPawnSK::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChildPawnSK::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChildPawnSK::UpdateSkeletalMeshes(USkeletalMesh* InSkeletalMesh, int IndexValue)
{
	switch (IndexValue)
	{
		case 0:
		{
			BodySK->SetSkeletalMesh(InSkeletalMesh, false);
			break;
		}
		case 1:
		{
			if (IsValid(InSkeletalMesh))
			{
				HairSK->SetSkeletalMesh(InSkeletalMesh, false);
				HairSK->SetVisibility(true);
			}
			else
			{
				HairSK->SetVisibility(false);
			}
			break;
		}
		case 2:
		{
			FaceSK->SetSkeletalMesh(InSkeletalMesh, false);
			break;
		}
		case 3:
		{
			if (IsValid(InSkeletalMesh))
			{
				HeadGearSK->SetSkeletalMesh(InSkeletalMesh, false);
				HeadGearSK->SetVisibility(true);
			}
			else
			{
				HeadGearSK->SetVisibility(false);
			}
			break;
		}
		case 4:
		{
			if (IsValid(InSkeletalMesh))
			{
				ShoulderSK->SetSkeletalMesh(InSkeletalMesh, false);
				ShoulderSK->SetVisibility(true);
			}
			else
			{
				ShoulderSK->SetVisibility(false);
			}
			break;
		}
		case 5:
		{
			ShoeSK->SetSkeletalMesh(InSkeletalMesh, false);
			break;
		}
		case 6:
		{
			GloveSK->SetSkeletalMesh(InSkeletalMesh, false);
			break;
		}
	}
}

