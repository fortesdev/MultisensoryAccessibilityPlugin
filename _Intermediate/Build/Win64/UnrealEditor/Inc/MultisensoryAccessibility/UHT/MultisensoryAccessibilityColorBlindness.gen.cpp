// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MultisensoryAccessibility/Public/MultisensoryAccessibilityColorBlindness.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMultisensoryAccessibilityColorBlindness() {}

// Begin Cross Module References
MULTISENSORYACCESSIBILITY_API UEnum* Z_Construct_UEnum_MultisensoryAccessibility_EAffectedColorCone();
MULTISENSORYACCESSIBILITY_API UEnum* Z_Construct_UEnum_MultisensoryAccessibility_EColorBlindMode();
MULTISENSORYACCESSIBILITY_API UEnum* Z_Construct_UEnum_MultisensoryAccessibility_EColorChangeTechnique();
UPackage* Z_Construct_UPackage__Script_MultisensoryAccessibility();
// End Cross Module References

// Begin Enum EAffectedColorCone
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAffectedColorCone;
static UEnum* EAffectedColorCone_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EAffectedColorCone.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EAffectedColorCone.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MultisensoryAccessibility_EAffectedColorCone, (UObject*)Z_Construct_UPackage__Script_MultisensoryAccessibility(), TEXT("EAffectedColorCone"));
	}
	return Z_Registration_Info_UEnum_EAffectedColorCone.OuterSingleton;
}
template<> MULTISENSORYACCESSIBILITY_API UEnum* StaticEnum<EAffectedColorCone>()
{
	return EAffectedColorCone_StaticEnum();
}
struct Z_Construct_UEnum_MultisensoryAccessibility_EAffectedColorCone_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Blue.DisplayName", "Blue (Tritanope)" },
		{ "Blue.Name", "EAffectedColorCone::Blue" },
		{ "BlueprintType", "true" },
		{ "Green.DisplayName", "Green (Deuteranope)" },
		{ "Green.Name", "EAffectedColorCone::Green" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityColorBlindness.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "EAffectedColorCone::None" },
		{ "Red.DisplayName", "Red (Protanope)" },
		{ "Red.Name", "EAffectedColorCone::Red" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EAffectedColorCone::None", (int64)EAffectedColorCone::None },
		{ "EAffectedColorCone::Red", (int64)EAffectedColorCone::Red },
		{ "EAffectedColorCone::Green", (int64)EAffectedColorCone::Green },
		{ "EAffectedColorCone::Blue", (int64)EAffectedColorCone::Blue },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MultisensoryAccessibility_EAffectedColorCone_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_MultisensoryAccessibility,
	nullptr,
	"EAffectedColorCone",
	"EAffectedColorCone",
	Z_Construct_UEnum_MultisensoryAccessibility_EAffectedColorCone_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_MultisensoryAccessibility_EAffectedColorCone_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_MultisensoryAccessibility_EAffectedColorCone_Statics::Enum_MetaDataParams), Z_Construct_UEnum_MultisensoryAccessibility_EAffectedColorCone_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_MultisensoryAccessibility_EAffectedColorCone()
{
	if (!Z_Registration_Info_UEnum_EAffectedColorCone.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAffectedColorCone.InnerSingleton, Z_Construct_UEnum_MultisensoryAccessibility_EAffectedColorCone_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EAffectedColorCone.InnerSingleton;
}
// End Enum EAffectedColorCone

// Begin Enum EColorChangeTechnique
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EColorChangeTechnique;
static UEnum* EColorChangeTechnique_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EColorChangeTechnique.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EColorChangeTechnique.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MultisensoryAccessibility_EColorChangeTechnique, (UObject*)Z_Construct_UPackage__Script_MultisensoryAccessibility(), TEXT("EColorChangeTechnique"));
	}
	return Z_Registration_Info_UEnum_EColorChangeTechnique.OuterSingleton;
}
template<> MULTISENSORYACCESSIBILITY_API UEnum* StaticEnum<EColorChangeTechnique>()
{
	return EColorChangeTechnique_StaticEnum();
}
struct Z_Construct_UEnum_MultisensoryAccessibility_EColorChangeTechnique_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "LUT.DisplayName", "LUT Color grading (Good contrast - Bad on HDR)" },
		{ "LUT.Name", "EColorChangeTechnique::LUT" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityColorBlindness.h" },
		{ "Shader.DisplayName", "Shaders (Good on HRD - Worse contrast" },
		{ "Shader.Name", "EColorChangeTechnique::Shader" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EColorChangeTechnique::LUT", (int64)EColorChangeTechnique::LUT },
		{ "EColorChangeTechnique::Shader", (int64)EColorChangeTechnique::Shader },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MultisensoryAccessibility_EColorChangeTechnique_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_MultisensoryAccessibility,
	nullptr,
	"EColorChangeTechnique",
	"EColorChangeTechnique",
	Z_Construct_UEnum_MultisensoryAccessibility_EColorChangeTechnique_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_MultisensoryAccessibility_EColorChangeTechnique_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_MultisensoryAccessibility_EColorChangeTechnique_Statics::Enum_MetaDataParams), Z_Construct_UEnum_MultisensoryAccessibility_EColorChangeTechnique_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_MultisensoryAccessibility_EColorChangeTechnique()
{
	if (!Z_Registration_Info_UEnum_EColorChangeTechnique.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EColorChangeTechnique.InnerSingleton, Z_Construct_UEnum_MultisensoryAccessibility_EColorChangeTechnique_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EColorChangeTechnique.InnerSingleton;
}
// End Enum EColorChangeTechnique

// Begin Enum EColorBlindMode
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EColorBlindMode;
static UEnum* EColorBlindMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EColorBlindMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EColorBlindMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MultisensoryAccessibility_EColorBlindMode, (UObject*)Z_Construct_UPackage__Script_MultisensoryAccessibility(), TEXT("EColorBlindMode"));
	}
	return Z_Registration_Info_UEnum_EColorBlindMode.OuterSingleton;
}
template<> MULTISENSORYACCESSIBILITY_API UEnum* StaticEnum<EColorBlindMode>()
{
	return EColorBlindMode_StaticEnum();
}
struct Z_Construct_UEnum_MultisensoryAccessibility_EColorBlindMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Correct.DisplayName", "Corrects" },
		{ "Correct.Name", "EColorBlindMode::Correct" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityColorBlindness.h" },
		{ "Simulate.DisplayName", "Simulates" },
		{ "Simulate.Name", "EColorBlindMode::Simulate" },
		{ "SimulateCorrected.DisplayName", "Simulate with correction" },
		{ "SimulateCorrected.Name", "EColorBlindMode::SimulateCorrected" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EColorBlindMode::Simulate", (int64)EColorBlindMode::Simulate },
		{ "EColorBlindMode::SimulateCorrected", (int64)EColorBlindMode::SimulateCorrected },
		{ "EColorBlindMode::Correct", (int64)EColorBlindMode::Correct },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MultisensoryAccessibility_EColorBlindMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_MultisensoryAccessibility,
	nullptr,
	"EColorBlindMode",
	"EColorBlindMode",
	Z_Construct_UEnum_MultisensoryAccessibility_EColorBlindMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_MultisensoryAccessibility_EColorBlindMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_MultisensoryAccessibility_EColorBlindMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_MultisensoryAccessibility_EColorBlindMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_MultisensoryAccessibility_EColorBlindMode()
{
	if (!Z_Registration_Info_UEnum_EColorBlindMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EColorBlindMode.InnerSingleton, Z_Construct_UEnum_MultisensoryAccessibility_EColorBlindMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EColorBlindMode.InnerSingleton;
}
// End Enum EColorBlindMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityColorBlindness_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EAffectedColorCone_StaticEnum, TEXT("EAffectedColorCone"), &Z_Registration_Info_UEnum_EAffectedColorCone, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2020239900U) },
		{ EColorChangeTechnique_StaticEnum, TEXT("EColorChangeTechnique"), &Z_Registration_Info_UEnum_EColorChangeTechnique, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1803705696U) },
		{ EColorBlindMode_StaticEnum, TEXT("EColorBlindMode"), &Z_Registration_Info_UEnum_EColorBlindMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2106708333U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityColorBlindness_h_2248252501(TEXT("/Script/MultisensoryAccessibility"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityColorBlindness_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityColorBlindness_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
