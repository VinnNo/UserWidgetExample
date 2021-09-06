// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CharacterEditorPawn.generated.h"

UCLASS()
class UIEXAMPLE_API ACharacterEditorPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACharacterEditorPawn(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Root")
	class USceneComponent* RootScene;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	class UCameraComponent* CameraComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<class UWPawnEditor> PawnEditorUIClass;

	// Instance of UI
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	class UWPawnEditor* PawnEditorUI = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Mesh")
	class AChildPawnSK* CharacterSK;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	float RotationRate = 150.0f;

	float RotationDirection = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	float ZoomInMax = 150.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	float ZoomOutMax = 800.0f;

	float ZoomNormal = 300.0f;

	float ZoomValue = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	float ZoomSpeed = 150.0f;

	// Default rotation for the CharacterSK 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	float DefaultCharacterYaw = 60.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FVector DefaultCharacterPosition = FVector(0.0f, -150.0f, 20.0f);

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetRotationRate(float Value);

	UFUNCTION(BlueprintCallable)
	void SetZoomDirection(float InDirection, bool bReset = false);


	UFUNCTION(BlueprintCallable)
	void UpdateRotation(float Delta);

	UFUNCTION(BlueprintCallable)
	void UpdateZoom(float Delta);

	UFUNCTION(BlueprintCallable)
	void UpdateCharacterHair(USkeletalMesh* Hair);

	UFUNCTION(BlueprintCallable)
	void UpdateCharacter(USkeletalMesh* InSkeletalMesh, int CategoryIndex);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
