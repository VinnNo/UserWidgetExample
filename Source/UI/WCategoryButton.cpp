// Fill out your copyright notice in the Description page of Project Settings.


#include "WCategoryButton.h"

#include "Engine.h"

UWCategoryButton::UWCategoryButton()
{
	OnClicked.AddDynamic(this, &UWCategoryButton::OnClick);
}

void UWCategoryButton::OnClick()
{
	OnButtonPressed.Broadcast(ButtonCategoryName, ButtonTypeName);
}


