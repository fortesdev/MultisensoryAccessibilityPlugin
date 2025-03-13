// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MultisensoryAccessibility/Public/MultisensoryAccessibilityBPLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMultisensoryAccessibilityBPLibrary() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
ENGINE_API UClass* Z_Construct_UClass_UMaterialParameterCollection_NoRegister();
MULTISENSORYACCESSIBILITY_API UClass* Z_Construct_UClass_AMultisensoryAccessibilityPPVolume_NoRegister();
MULTISENSORYACCESSIBILITY_API UClass* Z_Construct_UClass_UMultisensoryAccessibilityBPLibrary();
MULTISENSORYACCESSIBILITY_API UClass* Z_Construct_UClass_UMultisensoryAccessibilityBPLibrary_NoRegister();
MULTISENSORYACCESSIBILITY_API UEnum* Z_Construct_UEnum_MultisensoryAccessibility_EAffectedColorCone();
MULTISENSORYACCESSIBILITY_API UEnum* Z_Construct_UEnum_MultisensoryAccessibility_EColorBlindMode();
MULTISENSORYACCESSIBILITY_API UEnum* Z_Construct_UEnum_MultisensoryAccessibility_EColorChangeTechnique();
MULTISENSORYACCESSIBILITY_API UEnum* Z_Construct_UEnum_MultisensoryAccessibility_EColoringStyle();
UPackage* Z_Construct_UPackage__Script_MultisensoryAccessibility();
// End Cross Module References

// Begin Class UMultisensoryAccessibilityBPLibrary Function ColorBlindnessSupport
struct Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics
{
	struct MultisensoryAccessibilityBPLibrary_eventColorBlindnessSupport_Parms
	{
		EAffectedColorCone Cone;
		AMultisensoryAccessibilityPPVolume* Volume;
		UMaterialParameterCollection* Collection;
		EColorChangeTechnique technique;
		EColorBlindMode mode;
		float strength;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MultisensoryAccessibilityColor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Method for simulating and correcting the tree kinds of Dichromacy color blidness \n\x09* @param Cone The affected color cone (red, green or blue).\n\x09* @param Volume The post-processing volume (AMultisensoryAccessibilityPPVolume) to apply the changes (unbound or not). If not defined, the method will try to find one. In debug mode, the method is able to spawn one.\n\x09* @param Collection The instance of the material-collection as provided in the plugin, for real time changes in shader technique.\n\x09* @param technique Either color grading through LUT (worse in HDR, better constrast), or shader in a post-processing material (Better for HDR, worse contrast).\n\x09* @param mode The mode to use the plugin, either \"simulating\", \"correcting\" or previewing the \"simulation with correction\"\n\x09* @param strength The degree of color blindness, from 0 (none) to 1 (fully), as percentage.\n\x09*/" },
#endif
		{ "DisplayName", "Simulation and correction of different color blindness (Dichromacy)" },
		{ "Keywords", "MultisensoryAccessibility|Color Blindness" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Method for simulating and correcting the tree kinds of Dichromacy color blidness\n@param Cone The affected color cone (red, green or blue).\n@param Volume The post-processing volume (AMultisensoryAccessibilityPPVolume) to apply the changes (unbound or not). If not defined, the method will try to find one. In debug mode, the method is able to spawn one.\n@param Collection The instance of the material-collection as provided in the plugin, for real time changes in shader technique.\n@param technique Either color grading through LUT (worse in HDR, better constrast), or shader in a post-processing material (Better for HDR, worse contrast).\n@param mode The mode to use the plugin, either \"simulating\", \"correcting\" or previewing the \"simulation with correction\"\n@param strength The degree of color blindness, from 0 (none) to 1 (fully), as percentage." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Cone_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Cone;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Volume;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Collection;
	static const UECodeGen_Private::FBytePropertyParams NewProp_technique_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_technique;
	static const UECodeGen_Private::FBytePropertyParams NewProp_mode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_mode;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_strength;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::NewProp_Cone_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::NewProp_Cone = { "Cone", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MultisensoryAccessibilityBPLibrary_eventColorBlindnessSupport_Parms, Cone), Z_Construct_UEnum_MultisensoryAccessibility_EAffectedColorCone, METADATA_PARAMS(0, nullptr) }; // 2020239900
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::NewProp_Volume = { "Volume", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MultisensoryAccessibilityBPLibrary_eventColorBlindnessSupport_Parms, Volume), Z_Construct_UClass_AMultisensoryAccessibilityPPVolume_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::NewProp_Collection = { "Collection", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MultisensoryAccessibilityBPLibrary_eventColorBlindnessSupport_Parms, Collection), Z_Construct_UClass_UMaterialParameterCollection_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::NewProp_technique_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::NewProp_technique = { "technique", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MultisensoryAccessibilityBPLibrary_eventColorBlindnessSupport_Parms, technique), Z_Construct_UEnum_MultisensoryAccessibility_EColorChangeTechnique, METADATA_PARAMS(0, nullptr) }; // 1803705696
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::NewProp_mode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::NewProp_mode = { "mode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MultisensoryAccessibilityBPLibrary_eventColorBlindnessSupport_Parms, mode), Z_Construct_UEnum_MultisensoryAccessibility_EColorBlindMode, METADATA_PARAMS(0, nullptr) }; // 2106708333
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::NewProp_strength = { "strength", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MultisensoryAccessibilityBPLibrary_eventColorBlindnessSupport_Parms, strength), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MultisensoryAccessibilityBPLibrary_eventColorBlindnessSupport_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::NewProp_Cone_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::NewProp_Cone,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::NewProp_Volume,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::NewProp_Collection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::NewProp_technique_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::NewProp_technique,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::NewProp_mode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::NewProp_mode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::NewProp_strength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMultisensoryAccessibilityBPLibrary, nullptr, "ColorBlindnessSupport", nullptr, nullptr, Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::MultisensoryAccessibilityBPLibrary_eventColorBlindnessSupport_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::MultisensoryAccessibilityBPLibrary_eventColorBlindnessSupport_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMultisensoryAccessibilityBPLibrary::execColorBlindnessSupport)
{
	P_GET_ENUM(EAffectedColorCone,Z_Param_Cone);
	P_GET_OBJECT(AMultisensoryAccessibilityPPVolume,Z_Param_Volume);
	P_GET_OBJECT(UMaterialParameterCollection,Z_Param_Collection);
	P_GET_ENUM(EColorChangeTechnique,Z_Param_technique);
	P_GET_ENUM(EColorBlindMode,Z_Param_mode);
	P_GET_PROPERTY(FFloatProperty,Z_Param_strength);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UMultisensoryAccessibilityBPLibrary::ColorBlindnessSupport(EAffectedColorCone(Z_Param_Cone),Z_Param_Volume,Z_Param_Collection,EColorChangeTechnique(Z_Param_technique),EColorBlindMode(Z_Param_mode),Z_Param_strength);
	P_NATIVE_END;
}
// End Class UMultisensoryAccessibilityBPLibrary Function ColorBlindnessSupport

// Begin Class UMultisensoryAccessibilityBPLibrary Function LowContrastSupport
struct Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics
{
	struct MultisensoryAccessibilityBPLibrary_eventLowContrastSupport_Parms
	{
		EColoringStyle ColotStyle;
		FLinearColor OutlineColor;
		AMultisensoryAccessibilityPPVolume* Volume;
		UMaterialParameterCollection* Collection;
		float Strength;
		bool SimulatingLowVision;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MultisensoryAccessibilityContrast" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Method for improving the contrast and vision of a scene by enhancing the colours, adding borders to the elements, etc. \n\x09* @param ColotStyle The improvement to apply: simplified distinct colors, adjustable ourlines, monocrome, or normal.\n\x09* @param OutlineColor The outline color.\n\x09* @param Volume The post-processing volume (AMultisensoryAccessibilityPPVolume) to apply the changes (unbound or not). If not defined, the method will try to find one. In debug mode, the method is able to spawn one.\n\x09* @param Collection The instance of the material-collection as provided in the plugin, for real time changes in shader technique.\n\x09* @param Strength The level contrast correction, from 0 to 10. this affects the removal of details and thickness of the outlines.\n\x09* @param SimulatingLowVision If true, a non-gaussian blur will simulate the effects of low vision.\n\x09*/" },
#endif
		{ "DisplayName", "Increase of color, contrast and vision within a volume" },
		{ "Keywords", "MultisensoryAccessibility|Low Contrast" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityBPLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Method for improving the contrast and vision of a scene by enhancing the colours, adding borders to the elements, etc.\n@param ColotStyle The improvement to apply: simplified distinct colors, adjustable ourlines, monocrome, or normal.\n@param OutlineColor The outline color.\n@param Volume The post-processing volume (AMultisensoryAccessibilityPPVolume) to apply the changes (unbound or not). If not defined, the method will try to find one. In debug mode, the method is able to spawn one.\n@param Collection The instance of the material-collection as provided in the plugin, for real time changes in shader technique.\n@param Strength The level contrast correction, from 0 to 10. this affects the removal of details and thickness of the outlines.\n@param SimulatingLowVision If true, a non-gaussian blur will simulate the effects of low vision." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ColotStyle_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ColotStyle;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutlineColor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Volume;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Collection;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Strength;
	static void NewProp_SimulatingLowVision_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_SimulatingLowVision;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::NewProp_ColotStyle_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::NewProp_ColotStyle = { "ColotStyle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MultisensoryAccessibilityBPLibrary_eventLowContrastSupport_Parms, ColotStyle), Z_Construct_UEnum_MultisensoryAccessibility_EColoringStyle, METADATA_PARAMS(0, nullptr) }; // 1270363154
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::NewProp_OutlineColor = { "OutlineColor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MultisensoryAccessibilityBPLibrary_eventLowContrastSupport_Parms, OutlineColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::NewProp_Volume = { "Volume", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MultisensoryAccessibilityBPLibrary_eventLowContrastSupport_Parms, Volume), Z_Construct_UClass_AMultisensoryAccessibilityPPVolume_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::NewProp_Collection = { "Collection", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MultisensoryAccessibilityBPLibrary_eventLowContrastSupport_Parms, Collection), Z_Construct_UClass_UMaterialParameterCollection_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::NewProp_Strength = { "Strength", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MultisensoryAccessibilityBPLibrary_eventLowContrastSupport_Parms, Strength), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::NewProp_SimulatingLowVision_SetBit(void* Obj)
{
	((MultisensoryAccessibilityBPLibrary_eventLowContrastSupport_Parms*)Obj)->SimulatingLowVision = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::NewProp_SimulatingLowVision = { "SimulatingLowVision", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MultisensoryAccessibilityBPLibrary_eventLowContrastSupport_Parms), &Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::NewProp_SimulatingLowVision_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MultisensoryAccessibilityBPLibrary_eventLowContrastSupport_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::NewProp_ColotStyle_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::NewProp_ColotStyle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::NewProp_OutlineColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::NewProp_Volume,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::NewProp_Collection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::NewProp_Strength,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::NewProp_SimulatingLowVision,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMultisensoryAccessibilityBPLibrary, nullptr, "LowContrastSupport", nullptr, nullptr, Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::MultisensoryAccessibilityBPLibrary_eventLowContrastSupport_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::MultisensoryAccessibilityBPLibrary_eventLowContrastSupport_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMultisensoryAccessibilityBPLibrary::execLowContrastSupport)
{
	P_GET_ENUM(EColoringStyle,Z_Param_ColotStyle);
	P_GET_STRUCT(FLinearColor,Z_Param_OutlineColor);
	P_GET_OBJECT(AMultisensoryAccessibilityPPVolume,Z_Param_Volume);
	P_GET_OBJECT(UMaterialParameterCollection,Z_Param_Collection);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Strength);
	P_GET_UBOOL(Z_Param_SimulatingLowVision);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UMultisensoryAccessibilityBPLibrary::LowContrastSupport(EColoringStyle(Z_Param_ColotStyle),Z_Param_OutlineColor,Z_Param_Volume,Z_Param_Collection,Z_Param_Strength,Z_Param_SimulatingLowVision);
	P_NATIVE_END;
}
// End Class UMultisensoryAccessibilityBPLibrary Function LowContrastSupport

// Begin Class UMultisensoryAccessibilityBPLibrary
void UMultisensoryAccessibilityBPLibrary::StaticRegisterNativesUMultisensoryAccessibilityBPLibrary()
{
	UClass* Class = UMultisensoryAccessibilityBPLibrary::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ColorBlindnessSupport", &UMultisensoryAccessibilityBPLibrary::execColorBlindnessSupport },
		{ "LowContrastSupport", &UMultisensoryAccessibilityBPLibrary::execLowContrastSupport },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMultisensoryAccessibilityBPLibrary);
UClass* Z_Construct_UClass_UMultisensoryAccessibilityBPLibrary_NoRegister()
{
	return UMultisensoryAccessibilityBPLibrary::StaticClass();
}
struct Z_Construct_UClass_UMultisensoryAccessibilityBPLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "MultisensoryAccessibilityBPLibrary.h" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityBPLibrary.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_ColorBlindnessSupport, "ColorBlindnessSupport" }, // 1605569332
		{ &Z_Construct_UFunction_UMultisensoryAccessibilityBPLibrary_LowContrastSupport, "LowContrastSupport" }, // 3226835364
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMultisensoryAccessibilityBPLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UMultisensoryAccessibilityBPLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_MultisensoryAccessibility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMultisensoryAccessibilityBPLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMultisensoryAccessibilityBPLibrary_Statics::ClassParams = {
	&UMultisensoryAccessibilityBPLibrary::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMultisensoryAccessibilityBPLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UMultisensoryAccessibilityBPLibrary_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMultisensoryAccessibilityBPLibrary()
{
	if (!Z_Registration_Info_UClass_UMultisensoryAccessibilityBPLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMultisensoryAccessibilityBPLibrary.OuterSingleton, Z_Construct_UClass_UMultisensoryAccessibilityBPLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMultisensoryAccessibilityBPLibrary.OuterSingleton;
}
template<> MULTISENSORYACCESSIBILITY_API UClass* StaticClass<UMultisensoryAccessibilityBPLibrary>()
{
	return UMultisensoryAccessibilityBPLibrary::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMultisensoryAccessibilityBPLibrary);
UMultisensoryAccessibilityBPLibrary::~UMultisensoryAccessibilityBPLibrary() {}
// End Class UMultisensoryAccessibilityBPLibrary

// Begin Registration
struct Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityBPLibrary_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMultisensoryAccessibilityBPLibrary, UMultisensoryAccessibilityBPLibrary::StaticClass, TEXT("UMultisensoryAccessibilityBPLibrary"), &Z_Registration_Info_UClass_UMultisensoryAccessibilityBPLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMultisensoryAccessibilityBPLibrary), 2011000537U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityBPLibrary_h_3782989354(TEXT("/Script/MultisensoryAccessibility"),
	Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityBPLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityBPLibrary_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
