/* 
	Multi-sensory Accessibility Plugin for UE5
 	Copyright 2025, Francisco Fortes

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at: http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and limitations under the License.
*/

#include "MultisensoryAccessibilityLowVision.h"
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

#if WITH_EDITOR
	#include "ActorFactories/ActorFactory.h"
	#include "ActorFactories/ActorFactoryBoxVolume.h"
	#include "Editor.h"
	#include "Debugging/SKismetDebugTreeView.h"
	#include "Editor/EditorEngine.h"
#endif

#define LOCTEXT_NAMESPACE "FMultisensoryAccessibilityModule"

float UMultisensoryAccessibilityLowVision::LowVisionHandling(
		EColoringStyle ColotStyle,
		FLinearColor OutlineColor,
		AMultisensoryAccessibilityPPVolume* Volume,
		UMaterialParameterCollection* Collection,
		float Strength,
		bool SimulatingLowVision) 
{
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
	
	_postProcessVolume->Settings.WeightedBlendables.Array.Empty();

	if (SimulatingLowVision) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Simulating low vision"));	
		UMaterial* blurMaterial = LoadObject<UMaterial>(nullptr, 
			TEXT("Material/Script/Engine.Material'/MultisensoryAccessibility/MSBlur.MSBlur'")); 
		if (blurMaterial)
		{
			UE_LOG(LogTemp, Warning, TEXT("blurMaterial found"));
			_postProcessVolume->setMaterial(blurMaterial, 1.0);
		} else {
			UE_LOG(LogTemp, Warning, TEXT("blurMaterial NOT found"));
		}		
	} else 
	{
		UE_LOG(LogTemp, Warning, TEXT("NOT Simulating low vision"));		
	}

	UMaterial* highVMaterial = LoadObject<UMaterial>(nullptr, 
		TEXT("Material/Script/Engine.Material'/MultisensoryAccessibility/MSHighContrastMaterial.MSHighContrastMaterial'")); 
	if (highVMaterial)
	{
		UE_LOG(LogTemp, Warning, TEXT("highVMaterial found"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("highVMaterial NOT found"));
		return -1;
	}

	if (Collection)
	{
	 	UWorld* world = GEngine->GameViewport->GetWorld();
		UMaterialParameterCollectionInstance* MCInstance = world->GetParameterCollectionInstance(Collection);
		if (MCInstance) 
		{
            UE_LOG(LogTemp, Warning, TEXT("MSColorBlindnessMaterial - Material collection found!"));
            switch (ColotStyle)
	        {
			case EColoringStyle::Normal:
				UE_LOG(LogTemp, Warning, TEXT("No color change mode applied"));
			    MCInstance->SetScalarParameterValue(FName(*FString("contrastMode")), static_cast<float>(0));
			    break; 	
		    case EColoringStyle::HighContrast:
				UE_LOG(LogTemp, Warning, TEXT("High contrast color mode applied"));
			    MCInstance->SetScalarParameterValue(FName(*FString("contrastMode")), static_cast<float>(1));
			    break; 
		    case EColoringStyle::Monochrome:
				UE_LOG(LogTemp, Warning, TEXT("Monochromoe high contrast mode applied"));
			    MCInstance->SetScalarParameterValue(FName(*FString("contrastMode")), static_cast<float>(2));
			    break;
		    default:
			   break;
		    break; 
	        }
			
			float limitedStrength = Strength > 1 ? 1 : Strength;
			limitedStrength = Strength < 0 ? 0 : Strength;
			MCInstance->SetScalarParameterValue(FName(*FString("fDiffuseColorThreshold")), 1 - limitedStrength); // 1 is regular detail, decrease when strength increases
			MCInstance->SetScalarParameterValue(FName(*FString("outlineDilationRate")), limitedStrength * 3); // adjustment for a better mapping to the above
			MCInstance->SetVectorParameterValue(FName(*FString("OutlineColor")), OutlineColor);
			MCInstance->SetScalarParameterValue(FName(*FString("applyBlur")), SimulatingLowVision);
			_postProcessVolume->setMaterial(highVMaterial, 1.0);
		} else 
		{
			UE_LOG(LogTemp, Warning, TEXT("MSColorBlindnessMaterial - Material collection is missing, plugin cannot be used"));
		}
	}

    return -1;
}
