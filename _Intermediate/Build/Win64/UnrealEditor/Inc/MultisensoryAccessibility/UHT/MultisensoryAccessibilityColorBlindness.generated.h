// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MultisensoryAccessibilityColorBlindness.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MULTISENSORYACCESSIBILITY_MultisensoryAccessibilityColorBlindness_generated_h
#error "MultisensoryAccessibilityColorBlindness.generated.h already included, missing '#pragma once' in MultisensoryAccessibilityColorBlindness.h"
#endif
#define MULTISENSORYACCESSIBILITY_MultisensoryAccessibilityColorBlindness_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityColorBlindness_h


#define FOREACH_ENUM_EAFFECTEDCOLORCONE(op) \
	op(EAffectedColorCone::None) \
	op(EAffectedColorCone::Red) \
	op(EAffectedColorCone::Green) \
	op(EAffectedColorCone::Blue) 

enum class EAffectedColorCone : uint8;
template<> struct TIsUEnumClass<EAffectedColorCone> { enum { Value = true }; };
template<> MULTISENSORYACCESSIBILITY_API UEnum* StaticEnum<EAffectedColorCone>();

#define FOREACH_ENUM_ECOLORCHANGETECHNIQUE(op) \
	op(EColorChangeTechnique::LUT) \
	op(EColorChangeTechnique::Shader) 

enum class EColorChangeTechnique : uint8;
template<> struct TIsUEnumClass<EColorChangeTechnique> { enum { Value = true }; };
template<> MULTISENSORYACCESSIBILITY_API UEnum* StaticEnum<EColorChangeTechnique>();

#define FOREACH_ENUM_ECOLORBLINDMODE(op) \
	op(EColorBlindMode::Simulate) \
	op(EColorBlindMode::SimulateCorrected) \
	op(EColorBlindMode::Correct) 

enum class EColorBlindMode : uint8;
template<> struct TIsUEnumClass<EColorBlindMode> { enum { Value = true }; };
template<> MULTISENSORYACCESSIBILITY_API UEnum* StaticEnum<EColorBlindMode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
