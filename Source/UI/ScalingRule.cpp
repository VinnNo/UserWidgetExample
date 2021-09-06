// Fill out your copyright notice in the Description page of Project Settings.


#include "ScalingRule.h"

float UScalingRule::GetDPIScaleBasedOnSize(FIntPoint Size)
{
	Super::GetDPIScaleBasedOnSize(Size);

	/*
	* This is a dummy scaling rule, made simply to supress the engine error log spam
	*/
	return 1.0f;
}