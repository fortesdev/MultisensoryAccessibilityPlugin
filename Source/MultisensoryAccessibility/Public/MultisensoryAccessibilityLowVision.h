

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