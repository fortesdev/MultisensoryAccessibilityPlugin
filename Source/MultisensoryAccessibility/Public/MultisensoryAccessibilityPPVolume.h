

#pragma once

#include "Engine.h"
#include "MultisensoryAccessibilityPPVolume.generated.h"

UCLASS()
class AMultisensoryAccessibilityPPVolume : public APostProcessVolume // El nombre debe empezar segun la nomenclatura de Epic https://dev.epicgames.com/documentation/en-us/unreal-engine/gameplay-classes-in-unreal-engine
{
	GENERATED_BODY()

	public:
	AMultisensoryAccessibilityPPVolume();
	static AMultisensoryAccessibilityPPVolume* getOrCreateVolume();
	void setMaterial(UMaterial *aMaterial, float intensity);
};