// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "MultisensoryAccessibilityPPVolume.h"
#include "MultisensoryAccessibilityColorBlindness.h"
#include "MultisensoryAccessibilityLowVision.h"
#include "MultisensoryAccessibilityBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/



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

// Nota: Lo de abajo es una inline function para accerder a contenidos locales, como materiales, desde path absolutos
template <typename ObjClass>
static FORCEINLINE ObjClass* LoadObjFromPath(const FName& Path)
{
if (Path == NAME_None) return nullptr;

return Cast<ObjClass>(StaticLoadObject(ObjClass::StaticClass(), nullptr, *Path.ToString()));
}

static FORCEINLINE UMaterial* LoadMaterialFromPath(const FName& Path)
{
if (Path == NAME_None) return nullptr;

return LoadObjFromPath<UMaterial>(Path);
}