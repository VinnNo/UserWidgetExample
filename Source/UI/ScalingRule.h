// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DPICustomScalingRule.h"
#include "ScalingRule.generated.h"

/**
 * 
 */
UCLASS()
class UIEXAMPLE_API UScalingRule : public UDPICustomScalingRule
{
	GENERATED_BODY()
public:
	virtual float GetDPIScaleBasedOnSize(FIntPoint Size);


};
