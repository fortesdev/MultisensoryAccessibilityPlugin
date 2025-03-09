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
#include "MultisensoryAccessibilityColorBlindness.h"
#include "MultisensoryAccessibilityLowVision.h"
#include "MultisensoryAccessibilityBPLibrary.generated.h"

UCLASS()
class UMultisensoryAccessibilityBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
	
	/**
	* Method for simulating and correcting the tree kinds of Dichromacy color blidness 
	* @param Cone The affected color cone (red, green or blue).
	* @param Volume The post-processing volume (AMultisensoryAccessibilityPPVolume) to apply the changes (unbound or not). If not defined, the method will try to find one. In debug mode, the method is able to spawn one.
	* @param Collection The instance of the material-collection as provided in the plugin, for real time changes in shader technique.
	* @param technique Either color grading through LUT (worse in HDR, better constrast), or shader in a post-processing material (Better for HDR, worse contrast).
	* @param mode The mode to use the plugin, either "simulating", "correcting" or previewing the "simulation with correction"
	* @param strength The degree of color blindness, from 0 (none) to 1 (fully), as percentage.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Simulation and correction of different color blindness (Dichromacy)", 
			  Keywords = "MultisensoryAccessibility|Color Blindness"), Category = "MultisensoryAccessibilityColor")
	static float ColorBlindnessSupport(
		EAffectedColorCone Cone, 
		AMultisensoryAccessibilityPPVolume* Volume,
		UMaterialParameterCollection* Collection,
		EColorChangeTechnique technique,
		EColorBlindMode mode,
		float strength); 

	/**
	* Method for improving the contrast and vision of a scene by enhancing the colours, adding borders to the elements, etc. 
	* @param ColotStyle The improvement to apply: simplified distinct colors, adjustable ourlines, monocrome, or normal.
	* @param OutlineColor The outline color.
	* @param Volume The post-processing volume (AMultisensoryAccessibilityPPVolume) to apply the changes (unbound or not). If not defined, the method will try to find one. In debug mode, the method is able to spawn one.
	* @param Collection The instance of the material-collection as provided in the plugin, for real time changes in shader technique.
	* @param Strength The level contrast correction, from 0 to 10. this affects the removal of details and thickness of the outlines.
	* @param SimulatingLowVision If true, a non-gaussian blur will simulate the effects of low vision.
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Increase of color, contrast and vision within a volume", 
			  Keywords = "MultisensoryAccessibility|Low Contrast"), Category = "MultisensoryAccessibilityContrast")
	static float LowContrastSupport(
		EColoringStyle ColotStyle,
		FLinearColor OutlineColor,
		AMultisensoryAccessibilityPPVolume* Volume,
		UMaterialParameterCollection* Collection,
		float Strength,
		bool SimulatingLowVision);
};