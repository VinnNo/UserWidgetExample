// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChildPawnSK.generated.h"

UCLASS()
class UIEXAMPLE_API AChildPawnSK : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChildPawnSK(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMeshComponents")
		class USkeletalMeshComponent* BodySK;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMeshComponents")
		class USkeletalMeshComponent* HairSK;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMeshComponents")
		class USkeletalMeshComponent* FaceSK;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMeshComponents")
		class USkeletalMeshComponent* HeadGearSK;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMeshComponents")
		class USkeletalMeshComponent* ShoulderSK;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMeshComponents")
		class USkeletalMeshComponent* ShoeSK;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkeletalMeshComponents")
		class USkeletalMeshComponent* GloveSK;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default Meshes")
		class USkeletalMesh* DefaultBody;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default Meshes")
		class USkeletalMesh* DefaultHair;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default Meshes")
		class USkeletalMesh* DefaultFace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default Meshes")
		class USkeletalMesh* DefaultHead;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default Meshes")
		class USkeletalMesh* DefaultShoulder;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default Meshes")
		class USkeletalMesh* DefaultShoe;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default Meshes")
		class USkeletalMesh* DefaultGlove;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default Animation")
		UAnimSequence* DefaultAnimation;





	UFUNCTION(BlueprintCallable)
	void UpdateSkeletalMeshes(USkeletalMesh* InSkeletalMesh, int IndexValue);



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
