/* 
	Multi-sensory Accessibility Plugin for UE5
 	Copyright 2025, Francisco Fortes

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at: http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and limitations under the License.
*/

#include "MultisensoryAccessibilityColorBlindness.h"
#include "MultisensoryAccessibility.h"
#include "Engine.h"
#include "Logging/StructuredLog.h"
#include "MultisensoryAccessibilityPPVolume.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "UObject/UnrealType.h"
#include <string>
#include "Materials/MaterialExpression.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FMultisensoryAccessibilityModule"

FString UMultisensoryAccessibilityColorBlindness::GetLUTTexturePath(
	EAffectedColorCone Cone,
	EColorBlindMode mode) 
{
	FString texturePath = "/Script/Engine.Texture2D'/MultisensoryAccessibility/LUTs/";
	FString textureFilename = "";
	switch (Cone)
	{
		case EAffectedColorCone::None:
			// UE_LOG(LogTemp, Warning, TEXT("Cone NONE"));
			return textureFilename;
			break;
		case EAffectedColorCone::Red:
		    textureFilename += "protanope";
		    break; 
		case EAffectedColorCone::Green:
		    textureFilename += "deuteranope";
		    break;
    	case EAffectedColorCone::Blue:
		    textureFilename += "tritanope";
			break;
		default:
			return textureFilename;
		   	break;
		break; 
	}

	switch (mode)
	{
		case EColorBlindMode::Simulate:
		    textureFilename += "_simulate_lut";
		    break; 
		case EColorBlindMode::Correct:
		    textureFilename += "_correct_lut";
		    break;
    	case EColorBlindMode::SimulateCorrected:
		    textureFilename += "_daltonise_lut";
			break;
		default:
			return textureFilename;
		   	break;
		break; 
	}

	texturePath += textureFilename;
	texturePath += ".";
	texturePath += textureFilename;
	texturePath += "'";
	return texturePath;
}

float UMultisensoryAccessibilityColorBlindness::ColorBlindnessLUTHandling(
		EAffectedColorCone Cone, 
		AMultisensoryAccessibilityPPVolume* Volume,
		UMaterialParameterCollection* Collection,
		EColorBlindMode mode,
        float strength) 
{
	UE_LOG(LogTemp, Warning, TEXT("Enters ColorBlindnessLUTHandling"));
	AMultisensoryAccessibilityPPVolume* _postProcessVolume = Volume;
 	if (_postProcessVolume == nullptr) 
	{
		_postProcessVolume = AMultisensoryAccessibilityPPVolume::getOrCreateVolume();
		if (_postProcessVolume == nullptr) 
		{
			UE_LOG(LogTemp, Warning, TEXT("AMultisensoryAccessibilityPPVolume not provided, plugin cannot work without it"));	
			return -1;
		}
	}
	// we deactivate, if found, any dichromatic definition in the post processing material
	if (Collection)
	{
		UWorld* world = GEngine->GameViewport->GetWorld();
		UMaterialParameterCollectionInstance* MCInstance = world->GetParameterCollectionInstance(Collection);
		if (MCInstance) 
		{
            UE_LOG(LogTemp, Warning, TEXT("MSColorBlindnessMaterial - Material collection found!"));
			FString ParamString = "ColorVisionDeficiencyType";
			FName ParamName = FName(*ParamString);
			MCInstance->SetScalarParameterValue(ParamName, static_cast<float>(EAffectedColorCone::None)); // no shader
		}
	}

	FString texturePath = GetLUTTexturePath(Cone, mode);
	switch (Cone)
	{
		case EAffectedColorCone::None:
			_postProcessVolume->Settings.bOverride_ColorGradingIntensity = 0; // Deactivate any previous LUT definitionr
			_postProcessVolume->Settings.bOverride_ColorGradingLUT = 0;
			return -1;
			break;
		default:
		   	break;
		break; 
	}
	
	switch (mode)
	{
		case EColorBlindMode::Simulate, EColorBlindMode::Correct, EColorBlindMode::SimulateCorrected:
		    break; 
		default:
			return -1;
		   	break;
		break; 
	}

	UE_LOG(LogTemp, Log, TEXT("LUT texture path: %s"), *texturePath);
	UTexture* ColorBlindTexture = LoadObject<UTexture>(nullptr, *texturePath);
	// A reference to a texture is constructed with systemPath+'local path+filename.filename', example:
	// "/Script/Engine.Texture2D'/MultisensoryAccessibility/LUTs/tritanope_simulate_lut.tritanope_simulate_lut'"

	if (ColorBlindTexture) 
	{
		UE_LOG(LogTemp, Warning, TEXT("MSColorBlindness - LUT texture found!"));
		// Beware, FPostProcessSettings ppSettings = _postProcessVolume->Settings creates a copy instead of using the pointer reference
		_postProcessVolume->Settings.bOverride_ColorGradingIntensity = 1;
		_postProcessVolume->Settings.bOverride_ColorGradingLUT = 1;
		// Look up table texture to use
		_postProcessVolume->Settings.ColorGradingLUT = ColorBlindTexture;
		// Color grading lookup table intensity. 0 = no intensity, 1=full intensity 
		_postProcessVolume->Settings.ColorGradingIntensity = strength * 0.7; // Strength affects very drastically LUT, so we reduce to 60% compare to shader result

	} else 
	{
		UE_LOG(LogTemp, Warning, TEXT("MSColorBlindness - LUT texture NOT found!"));
	}
//	UE_LOG(LogTemp, Warning, TEXT("This is the ColorGradingLUT: %s"), *FString(pathPlugin));	

	return -1;
} 

float UMultisensoryAccessibilityColorBlindness::ColorBlindnessShaderHandling(
		EAffectedColorCone Cone, 
		AMultisensoryAccessibilityPPVolume* Volume,
		UMaterialParameterCollection* Collection,
		EColorBlindMode mode,
        float strength)
{   
 	AMultisensoryAccessibilityPPVolume* _postProcessVolume = Volume;
 	if (_postProcessVolume == nullptr) {
		_postProcessVolume = AMultisensoryAccessibilityPPVolume::getOrCreateVolume();
		if (_postProcessVolume == nullptr) {
			UE_LOG(LogTemp, Warning, TEXT("AMultisensoryAccessibilityPPVolume not provided, plugin cannot work without it"));	
			return -1;
		}
	}

	_postProcessVolume->Settings.bOverride_ColorGradingIntensity = 0; 
	_postProcessVolume->Settings.bOverride_ColorGradingLUT = 0;
	
	_postProcessVolume->Settings.WeightedBlendables.Array.Empty();

	UE_LOG(LogTemp, Warning, TEXT("AMultisensoryAccessibilityPPVolume found has no material, need to assign it"));	
	
	UMaterial* ColorBlindMaterial = LoadObject<UMaterial>(nullptr, 
	TEXT("Material/Script/Engine.Material'/MultisensoryAccessibility/MSColorBlindnessMaterial.MSColorBlindnessMaterial'")); 
		
	if (ColorBlindMaterial)
	{
		UE_LOG(LogTemp, Warning, TEXT("MSColorBlindnessMaterial.Succeeded()"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("MSColorBlindnessMaterial.Succeeded() NOPE"));
		return -1;
	}
	_postProcessVolume->setMaterial(ColorBlindMaterial, 1.0);

	// We change values based on the MaterialCollection received
	if (Collection)
	{
	 	UWorld* world = GEngine->GameViewport->GetWorld();
		UMaterialParameterCollectionInstance* MCInstance = world->GetParameterCollectionInstance(Collection);
		if (MCInstance) 
		{
            UE_LOG(LogTemp, Warning, TEXT("MSColorBlindnessMaterial - Material collection found!"));
            switch (mode)
	        {
		    case EColorBlindMode::Simulate:
			    MCInstance->SetScalarParameterValue(FName(*FString("bCorrecting")), static_cast<float>(0));
                MCInstance->SetScalarParameterValue(FName(*FString("bSimulateCorrecting")), static_cast<float>(0));
			    break; 
		    case EColorBlindMode::Correct:
			    MCInstance->SetScalarParameterValue(FName(*FString("bCorrecting")), static_cast<float>(1));
                MCInstance->SetScalarParameterValue(FName(*FString("bSimulateCorrecting")), static_cast<float>(0));
			    break;
    	    case EColorBlindMode::SimulateCorrected:
			    MCInstance->SetScalarParameterValue(FName(*FString("bCorrecting")), static_cast<float>(1));
                MCInstance->SetScalarParameterValue(FName(*FString("bSimulateCorrecting")), static_cast<float>(1)); // This needs bCorrectDeficiency apply - otherwise is just re-simulate
			    break;
		    default:
			   break;
		    break; 
	        }
			
			TArray<float> MatrixCVD = UMultisensoryAccessibilityColorBlindness::getCVDTable(Cone, strength);
			FLinearColor CVDR = FLinearColor(MatrixCVD[0], MatrixCVD[1], MatrixCVD[2]);
			FLinearColor CVDG = FLinearColor(MatrixCVD[3], MatrixCVD[4], MatrixCVD[5]);
			FLinearColor CVDB = FLinearColor(MatrixCVD[6], MatrixCVD[7], MatrixCVD[8]);
			FLinearColor DALTR = UMultisensoryAccessibilityColorBlindness::getDALTColor(0, Cone);
			FLinearColor DALTG = UMultisensoryAccessibilityColorBlindness::getDALTColor(1, Cone);
			FLinearColor DALTB = UMultisensoryAccessibilityColorBlindness::getDALTColor(2, Cone);
			// The FLinearColors are vectors, within the MaterialCollection, used as inputs for the post processing material
			MCInstance->SetVectorParameterValue(FName(*FString("CVDR")), CVDR);
			MCInstance->SetVectorParameterValue(FName(*FString("CVDG")), CVDG);
			MCInstance->SetVectorParameterValue(FName(*FString("CVDB")), CVDB);
			MCInstance->SetVectorParameterValue(FName(*FString("DALTR")), DALTR);
			MCInstance->SetVectorParameterValue(FName(*FString("DALTG")), DALTG);
			MCInstance->SetVectorParameterValue(FName(*FString("DALTB")), DALTB);
		} else {
			UE_LOG(LogTemp, Warning, TEXT("MSColorBlindnessMaterial - Material collection is missing, plugin cannot be used"));
		}
	}

    return -1;
}  

FLinearColor UMultisensoryAccessibilityColorBlindness::getDALTColor(
	int32 row,
	EAffectedColorCone Cone)
{
	switch (Cone)
		{
			case EAffectedColorCone::None:
				return FLinearColor(IDENTITYRBG[row*3], IDENTITYRBG[(row*3)+1], IDENTITYRBG[(row*3)+2]);
			case EAffectedColorCone::Red:
				return FLinearColor(MDALTR[row*3], MDALTR[(row*3)+1], MDALTR[(row*3)+2]);
			case EAffectedColorCone::Green:
				return FLinearColor(MDALTG[row*3], MDALTG[(row*3)+1], MDALTG[(row*3)+2]);
    		case EAffectedColorCone::Blue:
				return FLinearColor(MDALTB[row*3], MDALTB[(row*3)+1], MDALTB[(row*3)+2]);
			default:
				return FLinearColor(IDENTITYRBG[row*3], IDENTITYRBG[(row*3)+1], IDENTITYRBG[(row*3)+2]);
			break; 
		}
}

float UMultisensoryAccessibilityColorBlindness::interpolate(float low, float high, float weigth) 
{
	if (weigth == 0.0) {
		return low;
	} else {
		// Interpolation with weight = A + ((B – A) * w)
		UE_LOG(LogTemp, Log, TEXT("A: %f B %f w %f"), low, high, weigth);
		return low + (high - low) * weigth;		
	}
}

TArray<float> UMultisensoryAccessibilityColorBlindness::getCVDTable(
	EAffectedColorCone Cone,
	float strength)
{   
	const int32 size = 9; // 3 times 3 RGB values
	const int32 maxStrength = 9;
	int32 intStrength = static_cast<int32>(strength);
	float weigth = 0.0;
	if (intStrength > maxStrength) {
		intStrength = maxStrength;
	} else if (intStrength < maxStrength) { // if == there is nothing to interpolate above
		weigth = strength - intStrength; // ie. in case of strength of 8.435, we'll use a weight of 0.435 to interpolate between 8 and 9
	}
	UE_LOG(LogTemp, Log, TEXT("We got strength: %f intStrength %i weigth %f"), strength, intStrength, weigth);
	int32 indexTable = size * intStrength;
	TArray<float> table;
	// Hack to extract a subarray from another array, with [startIndex], size TArray<float> CVDR = TArray<float>(&MatrixCVD.GetData()[0],3);
	for (int i = indexTable; i<indexTable + size; i++) 
	{
		switch (Cone)
		{
			case EAffectedColorCone::None:
				table = {
					1.0, 0.0, 0.0,
					0.0, 1.0, 0.0,
					0.0, 0.0, 1.0,
				};
				return table;
				break;
			case EAffectedColorCone::Red:
			UE_LOG(LogTemp, Log, TEXT("We got strength: %f intStrength %i weigth %f i:%i"), strength, intStrength, weigth, i);
					table.Add(UMultisensoryAccessibilityColorBlindness::interpolate(
						ProtanopeCVDTable[i], 
						ProtanopeCVDTable[i+size], 
						weigth)
					);
			    break; 
			case EAffectedColorCone::Green:
					table.Add(UMultisensoryAccessibilityColorBlindness::interpolate(
						DeuteranopeCVDTable[i], 
						DeuteranopeCVDTable[i+size], 
						weigth)
					);
			    break;
    		case EAffectedColorCone::Blue:
					table.Add(UMultisensoryAccessibilityColorBlindness::interpolate(
						TritanopeCVDTable[i], 
						TritanopeCVDTable[i+size], 
						weigth)
					);
				break;
			default:
			break; 
		}
	}

	for (auto& aNumber : table) //For each loop
	{
		UE_LOG(LogTemp, Log, TEXT("Value: %f"), aNumber);
	}
	return table;
}