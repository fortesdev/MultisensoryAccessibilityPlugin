// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultisensoryAccessibilityBPLibrary.h"
#include "MultisensoryAccessibility.h"
#include "Engine.h"
#include "Logging/StructuredLog.h"
#include "MultisensoryAccessibilityPPVolume.h"
#include "MultisensoryAccessibilityColorBlindness.h"
#include "MultisensoryAccessibilityLowVision.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "UObject/UnrealType.h"
#include "Materials/MaterialExpression.h"

#if WITH_EDITOR
#include "ActorFactories/ActorFactory.h"
#include "ActorFactories/ActorFactoryBoxVolume.h"
#include "Editor.h"
#include "Debugging/SKismetDebugTreeView.h"
#include "Editor/EditorEngine.h"
#endif // #if WITH_EDITOR
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "Interfaces/IPluginManager.h"

UMultisensoryAccessibilityBPLibrary::UMultisensoryAccessibilityBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	// AddShaderSourceDirectoryMapping permite que un custom node de un material pueda incluir archivos de una carpeta no del motor (tenemos nuestro ush en Plugins/../Content)
	// Importante: No intentar imprimir logs aqui o el motor peta. Tampoco existe la definicion del plugin como tal, solo el del projecto, luego
	// accedemos a su path manualmente. Importante: Esto solo se carga una sola vez al abrir el proyecto (cerrar y reabrir en caso e cambios)
	// OJO, el archivo ush no es leido en tiempo real por el editor, sino solo al abrir el proyecto Y COMPILAR
//#if WITH_EDITOR
 //	FString ShaderDirectory = FPaths::Combine(FPaths::ProjectDir(), TEXT("Plugins/MultisensoryAccessibility/Shaders")); 
 //	AddShaderSourceDirectoryMapping("/Project", ShaderDirectory);
//#endif // #if WITH_EDITOR
}

float UMultisensoryAccessibilityBPLibrary::ColorBlindnessSupport(
		EAffectedColorCone Cone, 
		AMultisensoryAccessibilityPPVolume* Volume,
		UMaterialParameterCollection* Collection,
		EColorChangeTechnique technique,
		EColorBlindMode mode,
		float strength) 
{
	switch (technique)
	{
		case EColorChangeTechnique::LUT:
			return UMultisensoryAccessibilityColorBlindness::ColorBlindnessLUTHandling(Cone, Volume, Collection, mode, strength); 
			break; 
		case EColorChangeTechnique::Shader:
			 return UMultisensoryAccessibilityColorBlindness::ColorBlindnessShaderHandling(Cone, Volume, Collection, mode, strength * 10); // remove this and apply change in code somewhere else
			break;
		default:
			return -1; 
		break; 
	}
}

float UMultisensoryAccessibilityBPLibrary::LowContrastSupport(
		EColoringStyle ColotStyle,
		FLinearColor OutlineColor,
		AMultisensoryAccessibilityPPVolume* Volume,
		UMaterialParameterCollection* Collection,
		float Strength,
		bool SimulatingLowVision)
{
	return UMultisensoryAccessibilityLowVision::LowVisionHandling(
		ColotStyle, 
		OutlineColor, 
		Volume, 
		Collection, 
		Strength,
		SimulatingLowVision);
}


/*
Nasty code that does stuff


	//ResetAllShaderSourceDirectoryMappings();
	//FString ShaderDirectory = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("MultisensoryAccessibility"))->GetBaseDir(), TEXT("Shaders"));
	//  FString ShaderDirectory = FPaths::Combine(FPaths::ProjectDir(), TEXT("Shaders")); 
	//  UE_LOG(LogTemp, Warning, TEXT("This is the ShaderDirectory3: %s"), *FString(ShaderDirectory));	
	//  AddShaderSourceDirectoryMapping("/Project", ShaderDirectory);


//FPaths::ProjectContentDir()
UE_LOG(LogTemp, Warning, TEXT("AYYLMAO"));	
FString pathPj = FPaths::ProjectContentDir();
FString pathPlugin = IPluginManager::Get().FindPlugin(TEXT("MultisensoryAccessibility"))->GetBaseDir();
UE_LOG(LogTemp, Warning, TEXT("This is the pathPj: %s"), *FString(pathPj));
UE_LOG(LogTemp, Warning, TEXT("This is the pathPlugin: %s"), *FString(pathPlugin));	
//UE_LOG(LogTemp, Warning, TEXT(IPluginManager::Get().FindPlugin(TEXT("MultisensoryAccessibility"))->GetBaseDir()));


// Esto de abajo es como asignar materiales, por si hiciera falta
//	FString sPath = pathPlugin + "/Content/MyMaterial.MyMaterial";//"/Content/GreenBlindnessMaterial"; //"/Content/M_GreenBlindness.uasset";
//	UMaterial* MyMaterialA = LoadMaterialFromPath(FName(*sPath));
//	static ConstructorHelpers::FObjectFinder<UMaterial> MyMaterial(TEXT("/Script/Engine.Material'/MultisensoryAccessibility/MyMaterial.MyMaterial'"));//"/MultisensoryAccessibility/GreenBlindnessMaterial"));
	//UMaterial* MyMaterial = NewObject<UMaterial>();
	//UMaterialExpressionConstant* ZeroExpression = NewObject<UMaterialExpressionConstant>(MyMaterial);
//UMaterialExpressionConstant3Vector * BaseColorFactorNode = NewObject<UMaterialExpressionConstant3Vector>(NewMaterial);
//	BaseColorFactorNode->Constant = FColor::Red; //you can specify any color here;
 //   MyMaterial->BaseColor.Connect(0, BaseColorFactorNode);

//PostVolume->AddOrUpdateBlendable(BlendableInterface, 0.4);
	//void AddBlendable(TScriptInterface<IBlendableInterface> InBlendableObject, float InWeight)

	//FWeightedBlendable Element(1.0f, Blendables_DEPRECATED[i]);
	//ppSettings.WeightedBlendables.Array.Add(Element);
			TODO:
			3 - Si tiene materiales, borrarlos de WeightedBlendables
			4 - Segun el parametro de entrada:
				a) Crear material con valores correctos https://www.reddit.com/r/unrealengine/comments/18p1w2b/help_how_to_write_to_utexturerendertarget_in_c/ + https://forums.unrealengine.com/t/creating-a-new-material-in-c/357563/12
			 	b) asignarle ese al post processing volume https://dawnarc.com/2018/08/ue4modify-post-process-settings-at-run-time/
			


if (_postProcessVolume)
 	 	{
			UE_LOGFMT(LogTemp, Warning, "FindPostProcessVolume(): volume found! `{Name}`", _postProcessVolume->GetName());
	
		if (ppSettings.WeightedBlendables.Array.Num() > 0) 
		{
			UE_LOGFMT(LogTemp, Warning, "FindPostProcessVolume(): materiales count `{Name}`", ppSettings.WeightedBlendables.Array.Num());
			// wrong FWeightedBlendable* HoverMaterial = Cast<FWeightedBlendable>(ppSettings.WeightedBlendables.Array[0]);
			

		} else {
			if (!ppSettings.WeightedBlendables.Array.IsEmpty()) {
				UE_LOG(LogTemp, Warning, TEXT("WeightedBlendables! array vacio"));			
			} else {
				UE_LOG(LogTemp, Warning, TEXT("WeightedBlendables! array NO vacio"));	
			}
			UE_LOG(LogTemp, Warning, TEXT("NoHayMaterial! array vacio"));
		}
			
 	 	} else {
			UE_LOG(LogTemp, Warning, TEXT("FindPostProcessVolume(): volume NOT found!"));
 	 	}

	APlayerCameraManager* PlayerCameraMg = world->GetFirstPlayerController()->PlayerCameraManager;
	if (PlayerCameraMg) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerCameraMg found!"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerCameraMg NOT found!"));
	}


void UKismetMaterialLibrary::SetVectorParameterValue(UObject* WorldContextObject, UMaterialParameterCollection* Collection, FName ParameterName, const FLinearColor& ParameterValue)
{
	if (Collection)
	{
		if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
		{
			UMaterialParameterCollectionInstance* Instance = World->GetParameterCollectionInstance(Collection);

			const bool bFoundParameter = Instance->SetVectorParameterValue(ParameterName, ParameterValue);

			if (!bFoundParameter && !Instance->bLoggedMissingParameterWarning)
			{
				FFormatNamedArguments Arguments;
				Arguments.Add(TEXT("ParamName"), FText::FromName(ParameterName));
				FMessageLog("PIE").Warning()
					->AddToken(FTextToken::Create(LOCTEXT("SetVectorParamOn", "SetVectorParameterValue called on")))
					->AddToken(FUObjectToken::Create(Collection))
					->AddToken(FTextToken::Create(FText::Format(LOCTEXT("WithInvalidParam", "with invalid ParameterName '{ParamName}'. This is likely due to a Blueprint error."), Arguments)));
				Instance->bLoggedMissingParameterWarning = true;
			}
		}
	}
}

void UKismetMaterialLibrary::SetVectorParameterValue(UObject* WorldContextObject, UMaterialParameterCollection* Collection, FName ParameterName, const FLinearColor& ParameterValue)
{
	if (Collection)
	{
		if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
		{
			UMaterialParameterCollectionInstance* Instance = World->GetParameterCollectionInstance(Collection);

			const bool bFoundParameter = Instance->SetVectorParameterValue(ParameterName, ParameterValue);

			if (!bFoundParameter && !Instance->bLoggedMissingParameterWarning)
			{
				FFormatNamedArguments Arguments;
				Arguments.Add(TEXT("ParamName"), FText::FromName(ParameterName));
				FMessageLog("PIE").Warning()
					->AddToken(FTextToken::Create(LOCTEXT("SetVectorParamOn", "SetVectorParameterValue called on")))
					->AddToken(FUObjectToken::Create(Collection))
					->AddToken(FTextToken::Create(FText::Format(LOCTEXT("WithInvalidParam", "with invalid ParameterName '{ParamName}'. This is likely due to a Blueprint error."), Arguments)));
				Instance->bLoggedMissingParameterWarning = true;
			}
		}
	}
}
*/