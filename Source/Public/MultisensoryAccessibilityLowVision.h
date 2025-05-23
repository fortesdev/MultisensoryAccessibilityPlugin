
/* 
	Multi-sensory Accessibility Plugin for UE5
 	Copyright 2025, Francisco Fortes

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at: http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and limitations under the License.
*/

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "MultisensoryAccessibilityPPVolume.h"

UENUM(BlueprintType)
enum class EColoringStyle : uint8
{
	Normal UMETA(DisplayName="Normal (no color change)"),
	HighContrast UMETA(DisplayName="High contrast (simplified details and enhanced colors)"),
	Monochrome UMETA(DisplayName="Monochrome (no detail and only main outlines)")
};

class UMultisensoryAccessibilityLowVision
{

public:

	static float LowVisionHandling(
		EColoringStyle ColotStyle,
		FLinearColor OutlineColor,
		AMultisensoryAccessibilityPPVolume* Volume,
		UMaterialParameterCollection* Collection,
		float Strength,
		bool SimulatingLowVision); 

private:

};