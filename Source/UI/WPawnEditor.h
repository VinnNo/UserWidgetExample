// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Runtime/UMG/Public/UMG.h"

#include "UObject/ConstructorHelpers.h"

#include "Sound/SoundBase.h"

#include "WPawnEditor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
FBindableEvent_SkeletalMeshChanged,
USkeletalMesh*, SkeletalMeshWasChanged,
int, CategoryIndex);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
FBindableEvent_UpdateHair, USkeletalMesh*, HairVal);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
FBindableEvent_UpdateRotation, float, RotationalValue);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
FBindableEvent_StopRotation, float, RotationalValue);
/**
 * 
 */
UCLASS()
class UIEXAMPLE_API UWPawnEditor : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable)
		FBindableEvent_SkeletalMeshChanged OnSkeletalMeshChanged;

	UPROPERTY(BlueprintAssignable)
		FBindableEvent_UpdateHair OnHairChanged;

	UPROPERTY(BlueprintAssignable)
		FBindableEvent_UpdateRotation OnRotation;

	UPROPERTY(BlueprintAssignable)
		FBindableEvent_StopRotation OnRotationStop;

	// Widget Variables
	UPROPERTY(BlueprintReadOnly, Category = "Widget Values")
		TArray<FString> TextCategories;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Values")
		bool bIsDebug = true;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Values")
		bool bDebugOnScreenMessages = true;


	// Colors
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Colors")
		FColor ColorBG1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Colors")
		FColor ColorBG2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Colors")
		FColor ColorButton1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Colors")
		FColor ColorButton2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Colors")
		FColor ColorButtonInactive;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Names")
		TArray<FString> BodyNames;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Names")
		TArray<FString> HairNames;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Names")
		TArray<FString> HeadNames;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Names")
		TArray<FString> ShoulderNames;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Names")
		TArray<FString> ShoeNames;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Names")
		TArray<FString> GloveNames;


	/*
	* Menu SFX
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Sounds")
		class USoundBase* SoundAccept1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Sounds")
		class USoundBase* SoundAccept2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Sounds")
		class USoundBase* SoundBack1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Sounds")
		class USoundBase* SoundBack2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Sounds")
		class USoundBase* SoundError1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Sounds")
		class USoundBase* SoundError2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Sounds")
		class USoundBase* SoundMaximize;

	FVector2D ViewportSize = FVector2D(1.0f, 1.0f);
	FVector2D ResolutionSize = FVector2D(1.0f, 1.0f);


	/*
	* Widget Items
	*/

	UPROPERTY(BlueprintReadOnly, Category = "Widget Canvas")
		TArray<UCanvasPanel*> CanvasCategories;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Text")
		TArray<UTextBlock*> TextBlockCategories;

	// Buttons
	UPROPERTY(BlueprintReadOnly, Category = "Widget Buttons")
		TArray<UButton*> NextButtons;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Buttons")
		TArray<UButton*> PrevButtons;

	// Images
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Images")
		class UImage* ImageBG1 = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Images")
		class UImage* ImageBG2 = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Brushes")
		USlateBrushAsset* ButtonImagePressed = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Brushes")
		USlateBrushAsset* ButtonImageNormal = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Brushes")
		USlateBrushAsset* ButtonIndicatorRight = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Brushes")
		USlateBrushAsset* ButtonIndicatorLeft = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Brushes")
		USlateBrushAsset* ButtonRotationRight = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Brushes")
		USlateBrushAsset* ButtonRotationLeft = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Brushes")
		USlateBrushAsset* ButtonRotationRightPressed = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Brushes")
		USlateBrushAsset* ButtonRotationLeftPressed = nullptr;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Images")
		 TArray<UImage*> CategoryIcon;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Meshes")
		TArray<USkeletalMesh*> BodySkeletalMeshes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Meshes")
		TArray<USkeletalMesh*> HairSkeletalMeshes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Meshes")
		TArray<USkeletalMesh*> HalfHairSkeletalMeshes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Meshes")
		TArray<USkeletalMesh*> FaceSkeletalMeshes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Meshes")
		TArray<USkeletalMesh*> HeadGearSkeletalMeshes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Meshes")
		TArray<USkeletalMesh*> HelmSkeletalMeshes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Meshes")
		TArray<USkeletalMesh*> CrownSkeletalMeshes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Meshes")
		TArray<USkeletalMesh*> ShoulderSkeletalMeshes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Meshes")
		TArray<USkeletalMesh*> ShoeSkeletalMeshes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Meshes")
		TArray<USkeletalMesh*> GloveSkeletalMeshes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Meshes")
		TArray<int> CategoryIndexMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Meshes")
		TArray<int> CategoryIndexCurrent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget Meshes")
		int CrownThreshold = 11;

	// Dummy to populate arrays for none
	UPROPERTY(BlueprintReadOnly, Category = "Widget Meshes")
		USkeletalMesh* EmptyMesh;



	UPROPERTY(BlueprintReadOnly, Category = "Widget Inputs")
		float RotationValue = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Inputs")
		float ZoomValue = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Inputs")
	float ZoomOutMax = 1200.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Inputs")
	float ZoomInMax = 100.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Inputs")
	float ZoomReset = 300.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Inputs")
	UButton* RotationButtonRight = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Widget Inputs")
	UButton* RotationButtonLeft = nullptr;








	// Constructor
	UWPawnEditor(const FObjectInitializer& ObjectInitializer);

	// Functions
	virtual void NativeConstruct() override;

	void OnViewportResized(FViewport* ViewPort, uint32 Value);

	void UpdateCanvasPositions();

	virtual TSharedRef<SWidget> RebuildWidget() override;

	UFUNCTION(BlueprintCallable)
	void OnButtonCategoryPressed(FString ButtonCategoryName, FString ButtonTypeName);

	UFUNCTION(BlueprintCallable)
	void UpdateCharacter(FString ButtonCategoryName, FString ButtonTypeName, bool bInit = false);

	// This is just a caller to an almost identical delegate
	// but for changing hair in a sensical way
	void UpdateHair(USkeletalMesh* Hair);


	UFUNCTION(BlueprintCallable)
	void InputRotateRight();

	UFUNCTION(BlueprintCallable)
	void InputRotateLeft();

	UFUNCTION(BlueprintCallable)
	void InputRotationReset();

	UFUNCTION(BlueprintCallable)
	void InputZoomIn();

	UFUNCTION(BlueprintCallable)
	void InputZoomOut();

	UFUNCTION(BlueprintCallable)
	void InputZoomReset();
	
};
