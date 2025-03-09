/* 
	Multi-sensory Accessibility Plugin for UE5
 	Copyright 2025, Francisco Fortes

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at: http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and limitations under the License.
*/

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

UMultisensoryAccessibilityBPLibrary::UMultisensoryAccessibilityBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

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
			 return UMultisensoryAccessibilityColorBlindness::ColorBlindnessShaderHandling(Cone, Volume, Collection, mode, strength * 10); 
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
