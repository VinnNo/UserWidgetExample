// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"

#include "Runtime/UMG/Public/UMG.h"

#include "WCategoryButton.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPressedDelegate, 
FString, ButtonCategory,
FString, ButtonName);
/**
 * This class is just you're run of the mill UButton, however, it feeds more info via being pressed
 */
UCLASS()
class UIEXAMPLE_API UWCategoryButton : public UButton
{
	GENERATED_BODY()

public:

	UWCategoryButton();

	UPROPERTY()
	FString ButtonCategoryName;

	UPROPERTY()
	FString ButtonTypeName;

	UPROPERTY()
		FPressedDelegate OnButtonPressed;

	UFUNCTION()
	void OnClick();

};
