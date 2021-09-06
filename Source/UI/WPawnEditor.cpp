// Fill out your copyright notice in the Description page of Project Settings.


#include "WPawnEditor.h"

#include "UObject/ConstructorHelpers.h"

#include "Slate/SlateBrushAsset.h"
#include "Styling/SlateBrush.h"
#include "Styling/WidgetStyle.h"

#include "WCategoryButton.h"

#include "Engine/UserInterfaceSettings.h"

#include "Engine.h"

UWPawnEditor::UWPawnEditor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USlateBrushAsset> 
		BrushNomralObject(TEXT("/Game/UIExample/Brushes/T_Button_Fantasy_Normal_Brush.T_Button_Fantasy_Normal_Brush"));
	static ConstructorHelpers::FObjectFinder<USlateBrushAsset> 
		BrushPressedObject(TEXT("/Game/UIExample/Brushes/T_Button_Fantasy_Pressed_Brush.T_Button_Fantasy_Pressed_Brush"));

	if (BrushNomralObject.Succeeded())
		ButtonImageNormal = BrushNomralObject.Object;
	if (BrushPressedObject.Succeeded())
		ButtonImagePressed = BrushPressedObject.Object;


	static ConstructorHelpers::FObjectFinder<USlateBrushAsset> 
		BrushIRightObject(TEXT("/Game/UIExample/Brushes/T_Arrow_Right_Brush.T_Arrow_Right_Brush"));
	static ConstructorHelpers::FObjectFinder<USlateBrushAsset> 
		BrushILeftObject(TEXT("/Game/UIExample/Brushes/T_Arrow_Left_Brush.T_Arrow_Left_Brush"));

	if (BrushIRightObject.Succeeded())
		ButtonIndicatorRight = BrushIRightObject.Object;
	if (BrushILeftObject.Succeeded())
		ButtonIndicatorLeft = BrushILeftObject.Object;



	static ConstructorHelpers::FObjectFinder<USlateBrushAsset> 
		BrushRotateRightObject(TEXT("/Game/UIExample/Brushes/T_Right_Brush.T_Right_Brush"));
	static ConstructorHelpers::FObjectFinder<USlateBrushAsset>
		BrushRotateLeftObject(TEXT("/Game/UIExample/Brushes/T_Left_Brush.T_Left_Brush"));
	static ConstructorHelpers::FObjectFinder<USlateBrushAsset>
		BrushRotateRightPressedObject(TEXT("/Game/UIExample/Brushes/T_Right_Pressed_Brush.T_Right_Pressed_Brush"));
	static ConstructorHelpers::FObjectFinder<USlateBrushAsset>
		BrushRotateLeftPressedObject(TEXT("/Game/UIExample/Brushes/T_Left_Pressed_Brush.T_Left_Pressed_Brush"));

	if (BrushRotateRightObject.Succeeded())
		ButtonRotationRight = BrushRotateRightObject.Object;
	if (BrushRotateLeftObject.Succeeded())
		ButtonRotationLeft = BrushRotateLeftObject.Object;
	if (BrushRotateRightPressedObject.Succeeded())
		ButtonRotationRightPressed = BrushRotateRightPressedObject.Object;
	if (BrushRotateLeftPressedObject.Succeeded())
		ButtonRotationLeftPressed = BrushRotateLeftPressedObject.Object;


	// Body search
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> 
		Body1Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Cloth01SK.Cloth01SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Body2Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Cloth02SK.Cloth02SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Body3Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Cloth03SK.Cloth03SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Body4Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Cloth04SK.Cloth04SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Body5Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Cloth05SK.Cloth05SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Body6Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Cloth06SK.Cloth06SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Body7Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Cloth07SK.Cloth07SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Body8Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Cloth08SK.Cloth08SK"));
	
	// Body population
	if (Body1Object.Succeeded())
		BodySkeletalMeshes.Add(Body1Object.Object);
	if (Body2Object.Succeeded())
		BodySkeletalMeshes.Add(Body2Object.Object);
	if (Body3Object.Succeeded())
		BodySkeletalMeshes.Add(Body3Object.Object);
	if (Body4Object.Succeeded())
		BodySkeletalMeshes.Add(Body4Object.Object);
	if (Body5Object.Succeeded())
		BodySkeletalMeshes.Add(Body5Object.Object);
	if (Body6Object.Succeeded())
		BodySkeletalMeshes.Add(Body6Object.Object);
	if (Body7Object.Succeeded())
		BodySkeletalMeshes.Add(Body7Object.Object);
	if (Body8Object.Succeeded())
		BodySkeletalMeshes.Add(Body8Object.Object);

	// Hair full search
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Hair1Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Hair01SK.Hair01SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Hair2Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Hair02SK.Hair02SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Hair3Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Hair03SK.Hair03SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Hair4Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Hair04SK.Hair04SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Hair5Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Hair05SK.Hair05SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Hair6Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Hair06SK.Hair06SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Hair7Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Hair07SK.Hair07SK"));



	// Hair full population
	if (Hair1Object.Succeeded())
		HairSkeletalMeshes.Add(Hair1Object.Object);
	if (Hair2Object.Succeeded())
		HairSkeletalMeshes.Add(Hair2Object.Object);
	if (Hair3Object.Succeeded())
		HairSkeletalMeshes.Add(Hair3Object.Object);
	if (Hair4Object.Succeeded())
		HairSkeletalMeshes.Add(Hair4Object.Object);
	if (Hair5Object.Succeeded())
		HairSkeletalMeshes.Add(Hair5Object.Object);
	if (Hair6Object.Succeeded())
		HairSkeletalMeshes.Add(Hair6Object.Object);
	if (Hair7Object.Succeeded())
		HairSkeletalMeshes.Add(Hair7Object.Object);

	// Hair half search
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		HalfHair1Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Hair01HalfSK.Hair01HalfSK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		HalfHair2Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Hair02HalfSK.Hair02HalfSK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		HalfHair3Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Hair03HalfSK.Hair03HalfSK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		HalfHair4Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Hair04HalfSK.Hair04HalfSK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		HalfHair5Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Hair05HalfSK.Hair05HalfSK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		HalfHair6Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Hair06HalfSK.Hair06HalfSK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		HalfHair7Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Hair07HalfSK.Hair07HalfSK"));

	// Hair full population
	if (HalfHair1Object.Succeeded())
		HalfHairSkeletalMeshes.Add(HalfHair1Object.Object);
	if (HalfHair2Object.Succeeded())
		HalfHairSkeletalMeshes.Add(HalfHair2Object.Object);
	if (HalfHair3Object.Succeeded())
		HalfHairSkeletalMeshes.Add(HalfHair3Object.Object);
	if (HalfHair4Object.Succeeded())
		HalfHairSkeletalMeshes.Add(HalfHair4Object.Object);
	if (HalfHair5Object.Succeeded())
		HalfHairSkeletalMeshes.Add(HalfHair5Object.Object);
	if (HalfHair6Object.Succeeded())
		HalfHairSkeletalMeshes.Add(HalfHair6Object.Object);
	if (HalfHair7Object.Succeeded())
		HalfHairSkeletalMeshes.Add(HalfHair7Object.Object);

	// Face search
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Face1Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Face01SK.Face01SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Face2Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Face02SK.Face02SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Face3Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Face03SK.Face03SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Face4Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Face04SK.Face04SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Face5Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Face05SK.Face05SK"));

	// Face population
	if (Face1Object.Succeeded())
		FaceSkeletalMeshes.Add(Face1Object.Object);
	if (Face2Object.Succeeded())
		FaceSkeletalMeshes.Add(Face2Object.Object);
	if (Face3Object.Succeeded())
		FaceSkeletalMeshes.Add(Face3Object.Object);
	if (Face4Object.Succeeded())
		FaceSkeletalMeshes.Add(Face4Object.Object);
	if (Face5Object.Succeeded())
		FaceSkeletalMeshes.Add(Face5Object.Object);

	// Hat Search
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Hat1Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Hat01SK.Hat01SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Hat2Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Hat02SK.Hat02SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Hat3Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Hat03SK.Hat03SK"));

	// No helm!
	HeadGearSkeletalMeshes.Add(EmptyMesh);

	// Hat Population
	if (Hat1Object.Succeeded())
		HeadGearSkeletalMeshes.Add(Hat1Object.Object);
	if (Hat2Object.Succeeded())
		HeadGearSkeletalMeshes.Add(Hat2Object.Object);
	if (Hat3Object.Succeeded())
		HeadGearSkeletalMeshes.Add(Hat3Object.Object);

	// Helmet search
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Helm1Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Helm01SK.Helm01SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Helm2Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Helm02SK.Helm02SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Helm3Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Helm03SK.Helm03SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Helm4Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Helm04SK.Helm04SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Helm5Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Helm05SK.Helm05SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Helm6Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Helm06SK.Helm06SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Helm7Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Helm07SK.Helm07SK"));

	// Helm Population
	if (Helm1Object.Succeeded())
		HeadGearSkeletalMeshes.Add(Helm1Object.Object);
	if (Helm2Object.Succeeded())
		HeadGearSkeletalMeshes.Add(Helm2Object.Object);
	if (Helm3Object.Succeeded())
		HeadGearSkeletalMeshes.Add(Helm3Object.Object);
	if (Helm4Object.Succeeded())
		HeadGearSkeletalMeshes.Add(Helm4Object.Object);
	if (Helm5Object.Succeeded())
		HeadGearSkeletalMeshes.Add(Helm5Object.Object);
	if (Helm6Object.Succeeded())
		HeadGearSkeletalMeshes.Add(Helm6Object.Object);
	if (Helm7Object.Succeeded())
		HeadGearSkeletalMeshes.Add(Helm7Object.Object);

	// Crown Search
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Crown1Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Crown01SK.Crown01SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Crown2Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Crown02SK.Crown02SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Crown3Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Crown03SK.Crown03SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Crown4Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Crown04SK.Crown04SK"));

	// Crown Population
	// I ended up just adding these to the headgear array, however
	// it's not a TERRIBLE idea to keep them on their own up here too.
	if (Crown1Object.Succeeded())
		CrownSkeletalMeshes.Add(Crown1Object.Object);
	if (Crown2Object.Succeeded())
		CrownSkeletalMeshes.Add(Crown2Object.Object);
	if (Crown3Object.Succeeded())
		CrownSkeletalMeshes.Add(Crown3Object.Object);
	if (Crown4Object.Succeeded())
		CrownSkeletalMeshes.Add(Crown4Object.Object);

	// Crown Population on head gear
	if (Crown1Object.Succeeded())
		HeadGearSkeletalMeshes.Add(Crown1Object.Object);
	if (Crown2Object.Succeeded())
		HeadGearSkeletalMeshes.Add(Crown2Object.Object);
	if (Crown3Object.Succeeded())
		HeadGearSkeletalMeshes.Add(Crown3Object.Object);
	if (Crown4Object.Succeeded())
		HeadGearSkeletalMeshes.Add(Crown4Object.Object);

	// Shoulder SEarch
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Shoulder1Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/ShoulderPad01SK.ShoulderPad01SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Shoulder2Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/ShoulderPad02SK.ShoulderPad02SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Shoulder3Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/ShoulderPad03SK.ShoulderPad03SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Shoulder4Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/ShoulderPad04SK.ShoulderPad04SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Shoulder5Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/ShoulderPad05SK.ShoulderPad05SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Shoulder6Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/ShoulderPad06SK.ShoulderPad06SK"));

	ShoulderSkeletalMeshes.Add(EmptyMesh);

	// Shoulder population
	if (Shoulder1Object.Succeeded())
		ShoulderSkeletalMeshes.Add(Shoulder1Object.Object);
	if (Shoulder2Object.Succeeded())
		ShoulderSkeletalMeshes.Add(Shoulder2Object.Object);
	if (Shoulder3Object.Succeeded())
		ShoulderSkeletalMeshes.Add(Shoulder3Object.Object);
	if (Shoulder4Object.Succeeded())
		ShoulderSkeletalMeshes.Add(Shoulder4Object.Object);
	if (Shoulder5Object.Succeeded())
		ShoulderSkeletalMeshes.Add(Shoulder5Object.Object);
	if (Shoulder6Object.Succeeded())
		ShoulderSkeletalMeshes.Add(Shoulder6Object.Object);

	// Shoe search
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Shoe1Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Shoe01SK.Shoe01SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Shoe2Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Shoe02SK.Shoe02SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Shoe3Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Shoe03SK.Shoe03SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Shoe4Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Shoe04SK.Shoe04SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Shoe5Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Shoe05SK.Shoe05SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Shoe6Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Shoe06SK.Shoe06SK"));

	// Shoe population
	if (Shoe1Object.Succeeded())
		ShoeSkeletalMeshes.Add(Shoe1Object.Object);
	if (Shoe2Object.Succeeded())
		ShoeSkeletalMeshes.Add(Shoe2Object.Object);
	if (Shoe3Object.Succeeded())
		ShoeSkeletalMeshes.Add(Shoe3Object.Object);
	if (Shoe4Object.Succeeded())
		ShoeSkeletalMeshes.Add(Shoe4Object.Object);
	if (Shoe5Object.Succeeded())
		ShoeSkeletalMeshes.Add(Shoe5Object.Object);
	if (Shoe6Object.Succeeded())
		ShoeSkeletalMeshes.Add(Shoe6Object.Object);

	// Glove search
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Glove1Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Glove01SK.Glove01SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Glove2Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Glove02SK.Glove02SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Glove3Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Glove03SK.Glove03SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Glove4Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Glove04SK.Glove04SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Glove5Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Glove05SK.Glove05SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Glove6Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Glove06SK.Glove06SK"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		Glove7Object(TEXT("/Game/ModularRPGHeroesPolyart/Meshes/ModularBodyParts/Glove07SK.Glove07SK"));

	// Glove population
	if (Glove1Object.Succeeded())
		GloveSkeletalMeshes.Add(Glove1Object.Object);
	if (Glove2Object.Succeeded())
		GloveSkeletalMeshes.Add(Glove2Object.Object);
	if (Glove3Object.Succeeded())
		GloveSkeletalMeshes.Add(Glove3Object.Object);
	if (Glove4Object.Succeeded())
		GloveSkeletalMeshes.Add(Glove4Object.Object);
	if (Glove5Object.Succeeded())
		GloveSkeletalMeshes.Add(Glove5Object.Object);
	if (Glove6Object.Succeeded())
		GloveSkeletalMeshes.Add(Glove6Object.Object);
	if (Glove7Object.Succeeded())
		GloveSkeletalMeshes.Add(Glove7Object.Object);
}

void UWPawnEditor::NativeConstruct()
{
	Super::NativeConstruct();

	// Populate the base categories
	TextCategories.Add( TEXT("Clothing") );
	TextCategories.Add( TEXT("Hair") );
	TextCategories.Add( TEXT("Faces") );
	TextCategories.Add( TEXT("HeadGear") );
	TextCategories.Add( TEXT("Shoulders") );
	TextCategories.Add( TEXT("Shoes") );
	TextCategories.Add( TEXT("Gloves") );

	// Populate the indices to cycle
	// Body
	CategoryIndexMax.Add(BodySkeletalMeshes.Num() - 1);
	// Hair
	CategoryIndexMax.Add(HairSkeletalMeshes.Num() - 1);
	// Face
	CategoryIndexMax.Add(FaceSkeletalMeshes.Num() - 1);
	// Head Gear
	CategoryIndexMax.Add(HeadGearSkeletalMeshes.Num() - 1);
	// Shoulders
	CategoryIndexMax.Add(ShoulderSkeletalMeshes.Num() - 1);
	// Shoes
	CategoryIndexMax.Add(ShoeSkeletalMeshes.Num() - 1);
	// Gloves
	CategoryIndexMax.Add(GloveSkeletalMeshes.Num() - 1);


	// Set all current indices to zero, for starters
	for (int Itr = 0; Itr <= CategoryIndexMax.Num() - 1; ++Itr)
	{
		CategoryIndexCurrent.Add(0);
	}

	// This is actually useless here.
	if (GEngine && GEngine->GameViewport)
	{
		GEngine->GameViewport->Viewport->ViewportResizedEvent.AddUObject(this, &UWPawnEditor::OnViewportResized);
		GEngine->GameViewport->GetViewportSize(ViewportSize);
	}

	ResolutionSize.X = GSystemResolution.ResX;
	ResolutionSize.Y = GSystemResolution.ResY;


	// These all check for empty arrays first, in case a derived
	// class already has these populated, theoretically, of course
	if (BodyNames.Num() == 0)
	{
		BodyNames.Add(TEXT("Leather Garb"));
		BodyNames.Add(TEXT("Cloth Tunic"));
		BodyNames.Add(TEXT("Cloth Tunic 2"));
		BodyNames.Add(TEXT("Caster Garb"));
		BodyNames.Add(TEXT("Chainmail"));
		BodyNames.Add(TEXT("Galactic Getup"));
		BodyNames.Add(TEXT("Platemail"));
		BodyNames.Add(TEXT("Emerald Cuirass"));
	}

	if (HairNames.Num() == 0)
	{
		HairNames.Add(TEXT("Yo, Spikey!"));
		HairNames.Add(TEXT("Normie"));
		HairNames.Add(TEXT("White Bowl"));
		HairNames.Add(TEXT("Slick Blue"));
		HairNames.Add(TEXT("Bedhead"));
		HairNames.Add(TEXT("Hop-Scotch"));
		HairNames.Add(TEXT("Cyberpunk"));
	}

	if (HeadNames.Num() == 0)
	{
		HeadNames.Add(TEXT("None"));
		HeadNames.Add(TEXT("Aviator"));
		HeadNames.Add(TEXT("Wizard's Hat"));
		HeadNames.Add(TEXT("Mr.Moti"));
		HeadNames.Add(TEXT("Leather Norman"));
		HeadNames.Add(TEXT("Plate Sallet"));
		HeadNames.Add(TEXT("Iron Sallet"));
		HeadNames.Add(TEXT("Plate Barbute"));
		HeadNames.Add(TEXT("Kettle Sallet"));
		HeadNames.Add(TEXT("Raider"));
		HeadNames.Add(TEXT("Steel Gremlin"));
		HeadNames.Add(TEXT("Galactic Comms"));
		HeadNames.Add(TEXT("Gold Tiara"));
		HeadNames.Add(TEXT("Gold Tiara 2"));
		HeadNames.Add(TEXT("Star Lord"));
	}

	if (ShoulderNames.Num() == 0)
	{
		ShoulderNames.Add(TEXT("None"));
		ShoulderNames.Add(TEXT("Mixed Plate"));
		ShoulderNames.Add(TEXT("Steel Pauldrons"));
		ShoulderNames.Add(TEXT("Shoulder Blades"));
		ShoulderNames.Add(TEXT("Spiked Spaulders"));
		ShoulderNames.Add(TEXT("Bladed Pauldrons"));
		ShoulderNames.Add(TEXT("Leather Plate"));
	}

	if (ShoeNames.Num() == 0)
	{
		ShoeNames.Add(TEXT("Leather 1"));
		ShoeNames.Add(TEXT("Leather 2"));
		ShoeNames.Add(TEXT("Leather 3"));
		ShoeNames.Add(TEXT("Plate 1"));
		ShoeNames.Add(TEXT("Plate 2"));
		ShoeNames.Add(TEXT("Plate 3"));
	}

	if (GloveNames.Num() == 0)
	{
		GloveNames.Add(TEXT("Leather"));
		GloveNames.Add(TEXT("Plated Leather"));
		GloveNames.Add(TEXT("Plated Leather"));
		GloveNames.Add(TEXT("Plate 1"));
		GloveNames.Add(TEXT("Plate 2"));
		GloveNames.Add(TEXT("Plate 3"));
		GloveNames.Add(TEXT("Plate 4"));
	}


	// Initial broadcast on a delay
	FTimerHandle Handler;
	GetWorld()->GetTimerManager().SetTimer(Handler, [this]()
	{
		for (int Itr = 0; Itr < TextCategories.Num() - 1; ++Itr)
		{
			UpdateCharacter(TextCategories[Itr], TEXT("None"), true);
		}
	}, 0.1f, false);

	RebuildWidget();
	UpdateCanvasPositions();
}

void UWPawnEditor::OnViewportResized(FViewport* ViewPort, uint32 Value)
{
	if (GEngine && GEngine->GameViewport)
	{
		GEngine->GameViewport->GetViewportSize(ViewportSize);
		FString ResolutionString;
		ResolutionString = TEXT("Viewport: ");
		ResolutionString += FString::FromInt(ViewportSize.X);
		ResolutionString += TEXT(", ");
		ResolutionString += FString::FromInt(ViewportSize.Y);
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, ResolutionString);

		ResolutionSize.X = GSystemResolution.ResX;
		ResolutionSize.Y = GSystemResolution.ResY;

		ResolutionString = TEXT("Resolution: ");
		ResolutionString += FString::FromInt(ResolutionSize.X);
		ResolutionString += TEXT(", ");
		ResolutionString += FString::FromInt(ResolutionSize.Y);
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, ResolutionString);
	}

	UpdateCanvasPositions();
}

void UWPawnEditor::UpdateCanvasPositions()
{

	float ScaleX = ViewportSize.X / ResolutionSize.X;
	float ScaleY = ViewportSize.Y / ResolutionSize.Y;

	if (CanvasCategories.Num() > 0)
	{
		FString ResolutionString;

		ResolutionString = TEXT("ResolutionScale: ");
		ResolutionString += FString::SanitizeFloat(ScaleX);
		ResolutionString += TEXT(", ");
		ResolutionString += FString::SanitizeFloat(ScaleY);

		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, ResolutionString);

		for (int Itr = 0; Itr < CanvasCategories.Num(); ++Itr)
		{
			FVector2D PositionCanvasBase = FVector2D(ViewportSize.X, 0.0f);
			float YIncrement = 80.0f;
			FVector2D PositionCanvas = PositionCanvasBase;

			if (IsValid(CanvasCategories[Itr]))
			{
				UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(CanvasCategories[Itr]->Slot);
				if (CanvasSlot)
				{
					// Clamp values for Canvas placement
					FMath::Clamp(ScaleX, FMath::Min(0.25f, ScaleX), FMath::Min(ScaleX, 1.0f));
					FMath::Clamp(ScaleX, FMath::Min(0.25f, ScaleX), FMath::Min(ScaleX, 1.0f));

					float YOffset = YIncrement * (Itr * ScaleY);
					YOffset = FMath::Max( YOffset, FMath::Min(YIncrement * Itr, YOffset) );
					PositionCanvas.Y += YOffset;
				
					// Scale
					CanvasCategories[Itr]->SetRenderScale(FVector2D(ScaleX * 0.75f, ScaleY * 0.75f));

					FString SizeString = TEXT("CanvasScale: ");
					SizeString += FString::SanitizeFloat(ScaleX);
					SizeString += TEXT(", ");
					SizeString += FString::SanitizeFloat(ScaleY);

					//GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Purple, SizeString);

					PositionCanvas.X = ( ViewportSize.X - (600.0f * ScaleX) );

					// Padding
					PositionCanvas.X -= 10.0f;

					CanvasSlot->SetPosition(PositionCanvas);
				}
			}
		}
	}
	//Rotation Buttons

	FVector2D ButtonRightPosition = FVector2D( 1190.0f, FMath::Max( 96.0f,(ViewportSize.Y / 2) - 96) ) ;
	FVector2D ButtonLeftPosition = FVector2D(-22.5f, FMath::Max( 96.0f, (ViewportSize.Y / 2) - 96) );

	// Left
	if (IsValid(RotationButtonLeft))
	{

			ButtonLeftPosition.X += (8 * (ScaleX));

		
		//ButtonLeftPosition.Y *= ScaleY;
		UCanvasPanelSlot* LeftSlot = Cast<UCanvasPanelSlot>(RotationButtonLeft->Slot);
		if (LeftSlot)
		{
			LeftSlot->SetPosition(ButtonLeftPosition);
		}

		// Clamp values for Canvas placement
		FMath::Clamp(ScaleX, FMath::Min(0.25f, ScaleX), FMath::Min(ScaleX, 1.0f));
		FMath::Clamp(ScaleX, FMath::Min(0.25f, ScaleX), FMath::Min(ScaleX, 1.0f));

		RotationButtonLeft->SetRenderScale(FVector2D(ScaleX, ScaleY));
	}

	// Right
	if (IsValid(RotationButtonRight))
	{
		//ButtonRightPosition.Y *= ScaleY;
		ButtonRightPosition.X = (ViewportSize.X - (685.0f * ScaleX));
		UCanvasPanelSlot* RightSlot = Cast<UCanvasPanelSlot>(RotationButtonRight->Slot);
		if (RightSlot)
		{
			RightSlot->SetPosition(ButtonRightPosition);
		}

		// Clamp values for Canvas placement
		FMath::Clamp(ScaleX, FMath::Min(0.25f, ScaleX), FMath::Min(ScaleX, 1.0f));
		FMath::Clamp(ScaleX, FMath::Min(0.25f, ScaleX), FMath::Min(ScaleX, 1.0f));

		RotationButtonRight->SetRenderScale(FVector2D(ScaleX, ScaleY));
	}

}

TSharedRef<SWidget> UWPawnEditor::RebuildWidget()
{
	UPanelWidget* RootWidget = Cast<UPanelWidget>(GetRootWidget());

	if (!RootWidget)
	{
		if (WidgetTree)
		{
			RootWidget = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("RootWidget"));
		}

		// Root Anchors
		UCanvasPanelSlot* RootWidgetSlot = Cast<UCanvasPanelSlot>(RootWidget->Slot);
		if (RootWidgetSlot)
		{
			RootWidgetSlot->SetAnchors( FAnchors(0.0f, 0.0f, 0.0f, 0.0f) );
		}

		WidgetTree->RootWidget = RootWidget;
	}

	TSharedRef<SWidget> Widget = Super::RebuildWidget();

	
	if (RootWidget && WidgetTree)
	{
		// This could be filled automatically via gridbox, verticalbox etc
		// but it sorta defeats the purpose of this test/exercise
		if (TextCategories.Num() != 0 
		&& CanvasCategories.Num() != TextCategories.Num())
		{
			FVector2D PositionCanvasBase = FVector2D(1310.0f, 40.0f);

			FString PositionString = FString::FromInt(ViewportSize.X);
			//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, PositionString);

			float YIncrement = PositionCanvasBase.Y * 3;

			for (int Itr = 0; Itr < (TextCategories.Num()); ++Itr)
			{
				FVector2D PositionCanvas = PositionCanvasBase;
				float YOffset = YIncrement * Itr;

				PositionCanvas.Y += YOffset;

				FString CanvasString = TextCategories[Itr];
				CanvasString += TEXT("_Canvas");
				FName CanvasName = FName(*CanvasString);

				UCanvasPanel* Canvas = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), CanvasName);
				CanvasCategories.Add(Canvas);
				RootWidget->AddChild(Canvas);

				UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(Canvas->Slot);
				if (CanvasSlot)
				{
					CanvasSlot->SetAnchors(FAnchors(0.0f, 0.0f, 0.0f, 0.0f));
					CanvasSlot->bAutoSize = true;
					CanvasSlot->SetPosition(PositionCanvas);
				}

				// Buttons

				// Left
				FString NamedString = TextCategories[Itr];
				FString ButtonType = TEXT("Button_Left");
				FString NamedStringUpdated = NamedString + TEXT("_Button_Left");
				FName ButtonName = FName(*NamedStringUpdated);

				FVector2D ButtonSize = FVector2D(100.0f, 70.0f);

				UWCategoryButton* ButtonLeft = WidgetTree->ConstructWidget<UWCategoryButton>(UWCategoryButton::StaticClass(), ButtonName);
				ButtonLeft->ButtonCategoryName = NamedString;
				ButtonLeft->ButtonTypeName = ButtonType;

				// Right
				ButtonType = TEXT("Button_Right");
				NamedStringUpdated = NamedString + TEXT("_Button_Right");
				ButtonName = FName(*NamedStringUpdated);

				UWCategoryButton* ButtonRight = WidgetTree->ConstructWidget<UWCategoryButton>(UWCategoryButton::StaticClass(), ButtonName);
				ButtonRight->ButtonCategoryName = NamedString;
				ButtonRight->ButtonTypeName = ButtonType;

				// Assigning
				Canvas->AddChild(ButtonLeft);
				Canvas->AddChild(ButtonRight);

				ButtonLeft->OnButtonPressed.AddDynamic(this, &UWPawnEditor::OnButtonCategoryPressed);
				ButtonRight->OnButtonPressed.AddDynamic(this, &UWPawnEditor::OnButtonCategoryPressed);

				// Position
				UCanvasPanelSlot* ButtonLeftSlot = Cast<UCanvasPanelSlot>(ButtonLeft->Slot);
				if (ButtonLeftSlot)
				{
					ButtonLeftSlot->SetAnchors(FAnchors());
					ButtonLeftSlot->SetSize(ButtonSize);
				}

				UCanvasPanelSlot* ButtonRightSlot = Cast<UCanvasPanelSlot>(ButtonRight->Slot);
				if (ButtonRightSlot)
				{
					ButtonRightSlot->SetAnchors(FAnchors());
					ButtonRightSlot->SetSize(ButtonSize);
					ButtonRightSlot->SetPosition(FVector2D(460.0f, 0.0f));

				}

				// Styles for the buttons
				if (IsValid(ButtonImageNormal))
				{
					ButtonLeft->WidgetStyle.SetNormal(ButtonImageNormal->Brush);
					ButtonLeft->WidgetStyle.SetHovered(ButtonImageNormal->Brush);
					ButtonRight->WidgetStyle.SetNormal(ButtonImageNormal->Brush);
					ButtonRight->WidgetStyle.SetHovered(ButtonImageNormal->Brush);
				}
				if (IsValid(ButtonImagePressed))
				{
					ButtonLeft->WidgetStyle.SetPressed(ButtonImagePressed->Brush);
					ButtonLeft->WidgetStyle.SetDisabled(ButtonImagePressed->Brush);
					ButtonRight->WidgetStyle.SetPressed(ButtonImagePressed->Brush);
					ButtonRight->WidgetStyle.SetDisabled(ButtonImagePressed->Brush);

				}

				// Images for the Buttons
				UImage* BILeft = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
				UImage* BIRight = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
					
				// Add to buttons
				ButtonLeft->AddChild(BILeft);
				ButtonRight->AddChild(BIRight);

				// Set brushes for the button indicator images
				if (IsValid(ButtonIndicatorLeft))
				{
					BILeft->SetBrushFromAsset(ButtonIndicatorLeft);
				}
				if (IsValid(ButtonIndicatorRight))
				{
					BIRight->SetBrushFromAsset(ButtonIndicatorRight);
				}

				// Icon Image
				NamedStringUpdated = NamedString + TEXT("_Asset_Image");
				FName ImageName = FName(*NamedStringUpdated);
				UImage* AssetImage = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass(), ImageName);

				Canvas->AddChild(AssetImage);

				// Icon Size and Position
				UCanvasPanelSlot* AssetImageSlot = Cast<UCanvasPanelSlot>(AssetImage->Slot);
				if (AssetImageSlot)
				{
					AssetImageSlot->SetPosition(FVector2D(150.0f, 0.0f));
					AssetImageSlot->SetSize(FVector2D(100.0f, 100.0f));
				}
				AssetImage->ColorAndOpacity = FColor(0, 0, 0, 255);


				// Text Label
				NamedStringUpdated = TEXT("CategoryLabel");
				FName TextName = FName(*NamedStringUpdated);
				UTextBlock* TextLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TextName);

				Canvas->AddChild(TextLabel);

				TextLabel->SetText(FText::FromString(NamedString));

				// Asset Label; Shows names of the equipment on character
				NamedStringUpdated = TEXT("AssetLabel_") + FString::FromInt(Itr);
				TextName = FName(*NamedStringUpdated);
				UTextBlock* AssetLabel = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TextName);

				AssetLabel->bIsVariable = true;
				TextBlockCategories.Add(AssetLabel);
				Canvas->AddChild(AssetLabel);
				AssetLabel->SetRenderScale(FVector2D(0.725f, 0.725f));

				FString AssetNameString = NamedString + TEXT(" ") + FString::FromInt(Itr);

				AssetLabel->SetText(FText::FromString(AssetNameString));

				UCanvasPanelSlot* TextLabelSlot = Cast<UCanvasPanelSlot>(TextLabel->Slot);
				if (TextLabelSlot)
				{
					TextLabelSlot->SetPosition(FVector2D(270.0f, 10.0f));
				}	

				UCanvasPanelSlot* AssetLabelSlot = Cast<UCanvasPanelSlot>(AssetLabel->Slot);
				if (AssetLabelSlot)
				{
					AssetLabelSlot->SetPosition(FVector2D(250.0f, 60.0f));
				}
			}
		}
		// End Panel

		if (!RotationButtonLeft && !RotationButtonRight)
		{
			FString StringName = TEXT("ButtonRotateRight");
			FName NamedString = FName(*StringName);
			UButton* ButtonRight = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), NamedString);

			StringName = TEXT("ButtonRotateLeft");
			NamedString = FName(*StringName);
			UButton* ButtonLeft = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), NamedString);

			RotationButtonLeft = ButtonLeft;
			RotationButtonRight = ButtonRight;

			RootWidget->AddChild(ButtonRight);
			RootWidget->AddChild(ButtonLeft);

			ButtonLeft->SetPressMethod(EButtonPressMethod::ButtonPress);
			ButtonLeft->SetClickMethod(EButtonClickMethod::MouseDown);
			ButtonRight->SetPressMethod(EButtonPressMethod::ButtonPress);
			ButtonRight->SetClickMethod(EButtonClickMethod::MouseDown);

			ButtonLeft->OnClicked.AddDynamic(this, &UWPawnEditor::InputRotateLeft);
			ButtonLeft->OnReleased.AddDynamic(this, &UWPawnEditor::InputRotationReset);

			ButtonRight->OnClicked.AddDynamic(this, &UWPawnEditor::InputRotateRight);
			ButtonRight->OnReleased.AddDynamic(this, &UWPawnEditor::InputRotationReset);

			ButtonLeft->IsFocusable = false;
			ButtonRight->IsFocusable = false;

			if (IsValid(ButtonRotationRight))
			{
				ButtonRight->WidgetStyle.SetNormal(ButtonRotationRight->Brush);
				ButtonRight->WidgetStyle.SetDisabled(ButtonRotationRight->Brush);
				ButtonRight->WidgetStyle.SetHovered(ButtonRotationRight->Brush);
			}
			if (IsValid(ButtonRotationRightPressed))
			{
				ButtonRight->WidgetStyle.SetPressed(ButtonRotationRightPressed->Brush);
			}
			if (IsValid(ButtonRotationLeft))
			{
				ButtonLeft->WidgetStyle.SetNormal(ButtonRotationLeft->Brush);
				ButtonLeft->WidgetStyle.SetDisabled(ButtonRotationLeft->Brush);
				ButtonLeft->WidgetStyle.SetHovered(ButtonRotationLeft->Brush);
			}
			if (IsValid(ButtonRotationLeftPressed))
			{
				ButtonLeft->WidgetStyle.SetPressed(ButtonRotationLeftPressed->Brush);
			}

			UCanvasPanelSlot* ButtonRightSlot = Cast<UCanvasPanelSlot>(ButtonRight->Slot);
			if (ButtonRightSlot)
			{
				ButtonRightSlot->SetAnchors(FAnchors(0.0f, 0.0f, 0.0f, 0.0f));
				ButtonRightSlot->SetSize(FVector2D(85.0f, 150.0f));
				ButtonRightSlot->SetPosition(FVector2D(1190.0f, 470.0f));
			}

			UCanvasPanelSlot* ButtonLeftSlot = Cast<UCanvasPanelSlot>(ButtonLeft->Slot);
			if (ButtonLeftSlot)
			{
				ButtonLeftSlot->SetAnchors(FAnchors(0.0f, 0.0f, 0.0f, 0.0f));
				ButtonLeftSlot->SetSize(FVector2D(85.0f, 150.0f));
				ButtonLeftSlot->SetPosition(FVector2D(0.0f, 470.0f));
			}
		}
	}

	return Widget;
}

void UWPawnEditor::OnButtonCategoryPressed(FString ButtonCategoryName, FString ButtonTypeName)
{
	UpdateCharacter(ButtonCategoryName, ButtonTypeName, false);
}

void UWPawnEditor::UpdateCharacter(FString ButtonCategoryName, FString ButtonTypeName, bool bInit)
{

	int MatchingCase = TextCategories.IndexOfByKey<FString>(ButtonCategoryName);

	// 1 = right/next, -1 = left/previous
	int ShiftCategoryDirection = 0;

	FString Right = TEXT("Button_Right");
	FString Left = TEXT("Button_Left");

	// Cycle category index by input direction
	if (ButtonTypeName == Right)
	{
		ShiftCategoryDirection = 1;
	}
	else if (ButtonTypeName == Left)
	{
		ShiftCategoryDirection = -1;
	}

	// Cycle from end to start and back again
	if (ShiftCategoryDirection > 0)
	{
		if (CategoryIndexCurrent[MatchingCase] < CategoryIndexMax[MatchingCase])
		{
			CategoryIndexCurrent[MatchingCase] += 1;
		}
		else
		{
			CategoryIndexCurrent[MatchingCase] = 0;
		}
	}
	if (ShiftCategoryDirection < 0)
	{
		if (CategoryIndexCurrent[MatchingCase] > 0)
		{
			CategoryIndexCurrent[MatchingCase] -= 1;
		}
		else
		{
			CategoryIndexCurrent[MatchingCase] = CategoryIndexMax[MatchingCase];
		}
	}

	// Hax! Zero out for the initial broadcast
	if (bInit)
	{
		CategoryIndexCurrent[MatchingCase] = 0;
	}

	// Super simple default readout generation for the equipment
	FString AssetText = TextCategories[MatchingCase] + TEXT(" ");
	AssetText += FString::FromInt(CategoryIndexCurrent[MatchingCase] + 1);

	// Actual update of the meshes
	switch (MatchingCase)
	{
		// Body
		case 0:
		{
			AssetText = BodyNames[CategoryIndexCurrent[MatchingCase]];
			OnSkeletalMeshChanged.Broadcast(BodySkeletalMeshes[CategoryIndexCurrent[MatchingCase]], MatchingCase);
			break;
		}

		// Hair
		case 1:
		{
			AssetText = HairNames[CategoryIndexCurrent[MatchingCase]];
			if (CategoryIndexCurrent[3] >= 7
			&& CategoryIndexCurrent[3] <= 10)
			{
				UpdateHair(nullptr);
			}
			else if (CategoryIndexCurrent[3] >= CrownThreshold
			|| CategoryIndexCurrent[3] == 0)
			{
				OnSkeletalMeshChanged.Broadcast(HairSkeletalMeshes[CategoryIndexCurrent[MatchingCase]], MatchingCase);
			}
			else
			{
				OnSkeletalMeshChanged.Broadcast(HalfHairSkeletalMeshes[CategoryIndexCurrent[MatchingCase]], MatchingCase);
			}
			break;
		}

		// Face
		case 2:
		{
			AssetText = TEXT("Face ") + FString::FromInt(CategoryIndexCurrent[MatchingCase] + 1);
			OnSkeletalMeshChanged.Broadcast(FaceSkeletalMeshes[CategoryIndexCurrent[MatchingCase]], MatchingCase);
			break;
		}

		// Helm
		case 3:
		{
			AssetText = HeadNames[CategoryIndexCurrent[MatchingCase]];
			if (CategoryIndexCurrent[MatchingCase] >= 7
				&& CategoryIndexCurrent[MatchingCase] <= 10)
			{
				UpdateHair(nullptr);
			}
			else if (CategoryIndexCurrent[MatchingCase] >= CrownThreshold 
			|| CategoryIndexCurrent[MatchingCase] == 0)
			{
				//OnSkeletalMeshChanged.Broadcast(HalfHairSkeletalMeshes[CategoryIndexCurrent[1]], MatchingCase);
				UpdateHair(HairSkeletalMeshes[CategoryIndexCurrent[1]]);
			}
			else
			{
				//OnSkeletalMeshChanged.Broadcast(HairSkeletalMeshes[CategoryIndexCurrent[1]], MatchingCase);
				UpdateHair(HalfHairSkeletalMeshes[CategoryIndexCurrent[1]]);
			}
			OnSkeletalMeshChanged.Broadcast(HeadGearSkeletalMeshes[CategoryIndexCurrent[MatchingCase]], MatchingCase);
			break;
		}

		// Shoulder
		case 4:
		{
			AssetText = ShoulderNames[CategoryIndexCurrent[MatchingCase]];
			OnSkeletalMeshChanged.Broadcast(ShoulderSkeletalMeshes[CategoryIndexCurrent[MatchingCase]], MatchingCase);
			break;
		}

		// Shoe
		case 5:
		{
			AssetText = ShoeNames[CategoryIndexCurrent[MatchingCase]];
			OnSkeletalMeshChanged.Broadcast(ShoeSkeletalMeshes[CategoryIndexCurrent[MatchingCase]], MatchingCase);
			break;
		}

		// Glove
		case 6:
		{
			AssetText = GloveNames[CategoryIndexCurrent[MatchingCase]];
			OnSkeletalMeshChanged.Broadcast(GloveSkeletalMeshes[CategoryIndexCurrent[MatchingCase]], MatchingCase);
			break;
		}
	}

	/*
	* This text is being set down here due to a possible need to modify the string value
	* within the switch statement or during the delegate via BP's
	*/
	if (IsValid(TextBlockCategories[MatchingCase]))
	{
		TextBlockCategories[MatchingCase]->SetText(FText::FromString(AssetText));
	}

	FString Printer = FString::FromInt(CategoryIndexCurrent[MatchingCase]);
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, Printer);
}

void UWPawnEditor::UpdateHair(USkeletalMesh* Hair)
{
	OnHairChanged.Broadcast(Hair);
}

void UWPawnEditor::InputRotateLeft()
{
	RotationValue = 1.0f;
	OnRotation.Broadcast(RotationValue);
}

void UWPawnEditor::InputRotateRight()
{
	RotationValue = -1.0f;
	OnRotation.Broadcast(RotationValue);
}

void UWPawnEditor::InputRotationReset()
{
	RotationValue = 0.0f;
	OnRotation.Broadcast(RotationValue);
}

// Didn't get around to this.
void UWPawnEditor::InputZoomIn()
{

}

void UWPawnEditor::InputZoomOut()
{

}

void UWPawnEditor::InputZoomReset()
{

}


