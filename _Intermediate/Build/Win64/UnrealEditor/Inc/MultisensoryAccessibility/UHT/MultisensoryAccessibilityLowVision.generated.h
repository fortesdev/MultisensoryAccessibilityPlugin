// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MultisensoryAccessibilityLowVision.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MULTISENSORYACCESSIBILITY_MultisensoryAccessibilityLowVision_generated_h
#error "MultisensoryAccessibilityLowVision.generated.h already included, missing '#pragma once' in MultisensoryAccessibilityLowVision.h"
#endif
#define MULTISENSORYACCESSIBILITY_MultisensoryAccessibilityLowVision_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityLowVision_h


#define FOREACH_ENUM_ECOLORINGSTYLE(op) \
	op(EColoringStyle::Normal) \
	op(EColoringStyle::HighContrast) \
	op(EColoringStyle::Monochrome) 

enum class EColoringStyle : uint8;
template<> struct TIsUEnumClass<EColoringStyle> { enum { Value = true }; };
template<> MULTISENSORYACCESSIBILITY_API UEnum* StaticEnum<EColoringStyle>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
