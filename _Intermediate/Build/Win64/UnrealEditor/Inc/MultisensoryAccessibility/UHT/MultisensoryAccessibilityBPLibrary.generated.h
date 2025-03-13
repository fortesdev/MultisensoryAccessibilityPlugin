// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MultisensoryAccessibilityBPLibrary.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AMultisensoryAccessibilityPPVolume;
class UMaterialParameterCollection;
enum class EAffectedColorCone : uint8;
enum class EColorBlindMode : uint8;
enum class EColorChangeTechnique : uint8;
enum class EColoringStyle : uint8;
struct FLinearColor;
#ifdef MULTISENSORYACCESSIBILITY_MultisensoryAccessibilityBPLibrary_generated_h
#error "MultisensoryAccessibilityBPLibrary.generated.h already included, missing '#pragma once' in MultisensoryAccessibilityBPLibrary.h"
#endif
#define MULTISENSORYACCESSIBILITY_MultisensoryAccessibilityBPLibrary_generated_h

#define FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityBPLibrary_h_23_RPC_WRAPPERS \
	DECLARE_FUNCTION(execLowContrastSupport); \
	DECLARE_FUNCTION(execColorBlindnessSupport);


#define FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityBPLibrary_h_23_INCLASS \
private: \
	static void StaticRegisterNativesUMultisensoryAccessibilityBPLibrary(); \
	friend struct Z_Construct_UClass_UMultisensoryAccessibilityBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UMultisensoryAccessibilityBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MultisensoryAccessibility"), NO_API) \
	DECLARE_SERIALIZER(UMultisensoryAccessibilityBPLibrary)


#define FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityBPLibrary_h_23_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMultisensoryAccessibilityBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMultisensoryAccessibilityBPLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMultisensoryAccessibilityBPLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMultisensoryAccessibilityBPLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMultisensoryAccessibilityBPLibrary(UMultisensoryAccessibilityBPLibrary&&); \
	UMultisensoryAccessibilityBPLibrary(const UMultisensoryAccessibilityBPLibrary&); \
public: \
	NO_API virtual ~UMultisensoryAccessibilityBPLibrary();


#define FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityBPLibrary_h_20_PROLOG
#define FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityBPLibrary_h_23_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityBPLibrary_h_23_RPC_WRAPPERS \
	FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityBPLibrary_h_23_INCLASS \
	FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityBPLibrary_h_23_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MULTISENSORYACCESSIBILITY_API UClass* StaticClass<class UMultisensoryAccessibilityBPLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityBPLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
