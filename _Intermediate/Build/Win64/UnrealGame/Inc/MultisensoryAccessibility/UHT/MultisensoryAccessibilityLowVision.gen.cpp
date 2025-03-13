// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MultisensoryAccessibility/Public/MultisensoryAccessibilityLowVision.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMultisensoryAccessibilityLowVision() {}

// Begin Cross Module References
MULTISENSORYACCESSIBILITY_API UEnum* Z_Construct_UEnum_MultisensoryAccessibility_EColoringStyle();
UPackage* Z_Construct_UPackage__Script_MultisensoryAccessibility();
// End Cross Module References

// Begin Enum EColoringStyle
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EColoringStyle;
static UEnum* EColoringStyle_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EColoringStyle.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EColoringStyle.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MultisensoryAccessibility_EColoringStyle, (UObject*)Z_Construct_UPackage__Script_MultisensoryAccessibility(), TEXT("EColoringStyle"));
	}
	return Z_Registration_Info_UEnum_EColoringStyle.OuterSingleton;
}
template<> MULTISENSORYACCESSIBILITY_API UEnum* StaticEnum<EColoringStyle>()
{
	return EColoringStyle_StaticEnum();
}
struct Z_Construct_UEnum_MultisensoryAccessibility_EColoringStyle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HighContrast.DisplayName", "High contrast (simplified details and enhanced colors)" },
		{ "HighContrast.Name", "EColoringStyle::HighContrast" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityLowVision.h" },
		{ "Monochrome.DisplayName", "Monochrome (no detail and only main outlines)" },
		{ "Monochrome.Name", "EColoringStyle::Monochrome" },
		{ "Normal.DisplayName", "Normal (no color change)" },
		{ "Normal.Name", "EColoringStyle::Normal" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EColoringStyle::Normal", (int64)EColoringStyle::Normal },
		{ "EColoringStyle::HighContrast", (int64)EColoringStyle::HighContrast },
		{ "EColoringStyle::Monochrome", (int64)EColoringStyle::Monochrome },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MultisensoryAccessibility_EColoringStyle_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_MultisensoryAccessibility,
	nullptr,
	"EColoringStyle",
	"EColoringStyle",
	Z_Construct_UEnum_MultisensoryAccessibility_EColoringStyle_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_MultisensoryAccessibility_EColoringStyle_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_MultisensoryAccessibility_EColoringStyle_Statics::Enum_MetaDataParams), Z_Construct_UEnum_MultisensoryAccessibility_EColoringStyle_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_MultisensoryAccessibility_EColoringStyle()
{
	if (!Z_Registration_Info_UEnum_EColoringStyle.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EColoringStyle.InnerSingleton, Z_Construct_UEnum_MultisensoryAccessibility_EColoringStyle_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EColoringStyle.InnerSingleton;
}
// End Enum EColoringStyle

// Begin Registration
struct Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityLowVision_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EColoringStyle_StaticEnum, TEXT("EColoringStyle"), &Z_Registration_Info_UEnum_EColoringStyle, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1270363154U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityLowVision_h_3916716117(TEXT("/Script/MultisensoryAccessibility"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityLowVision_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityLowVision_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
