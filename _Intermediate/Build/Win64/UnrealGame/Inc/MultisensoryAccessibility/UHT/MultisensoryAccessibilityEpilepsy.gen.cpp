// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MultisensoryAccessibility/Public/MultisensoryAccessibilityEpilepsy.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMultisensoryAccessibilityEpilepsy() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_ACameraActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneCaptureComponent2D_NoRegister();
MULTISENSORYACCESSIBILITY_API UClass* Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy();
MULTISENSORYACCESSIBILITY_API UClass* Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_NoRegister();
MULTISENSORYACCESSIBILITY_API UFunction* Z_Construct_UDelegateFunction_MultisensoryAccessibility_EpilepsyDelegate__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_MultisensoryAccessibility();
// End Cross Module References

// Begin Delegate FEpilepsyDelegate
struct Z_Construct_UDelegateFunction_MultisensoryAccessibility_EpilepsyDelegate__DelegateSignature_Statics
{
	struct _Script_MultisensoryAccessibility_eventEpilepsyDelegate_Parms
	{
		bool blinkDetected;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// https://benui.ca/unreal/delegates-advanced/\n" },
#endif
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityEpilepsy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "https:benui.ca/unreal/delegates-advanced/" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_blinkDetected_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_blinkDetected;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UDelegateFunction_MultisensoryAccessibility_EpilepsyDelegate__DelegateSignature_Statics::NewProp_blinkDetected_SetBit(void* Obj)
{
	((_Script_MultisensoryAccessibility_eventEpilepsyDelegate_Parms*)Obj)->blinkDetected = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_MultisensoryAccessibility_EpilepsyDelegate__DelegateSignature_Statics::NewProp_blinkDetected = { "blinkDetected", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(_Script_MultisensoryAccessibility_eventEpilepsyDelegate_Parms), &Z_Construct_UDelegateFunction_MultisensoryAccessibility_EpilepsyDelegate__DelegateSignature_Statics::NewProp_blinkDetected_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_MultisensoryAccessibility_EpilepsyDelegate__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MultisensoryAccessibility_EpilepsyDelegate__DelegateSignature_Statics::NewProp_blinkDetected,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MultisensoryAccessibility_EpilepsyDelegate__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_MultisensoryAccessibility_EpilepsyDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_MultisensoryAccessibility, nullptr, "EpilepsyDelegate__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_MultisensoryAccessibility_EpilepsyDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MultisensoryAccessibility_EpilepsyDelegate__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_MultisensoryAccessibility_EpilepsyDelegate__DelegateSignature_Statics::_Script_MultisensoryAccessibility_eventEpilepsyDelegate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MultisensoryAccessibility_EpilepsyDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_MultisensoryAccessibility_EpilepsyDelegate__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_MultisensoryAccessibility_EpilepsyDelegate__DelegateSignature_Statics::_Script_MultisensoryAccessibility_eventEpilepsyDelegate_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_MultisensoryAccessibility_EpilepsyDelegate__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_MultisensoryAccessibility_EpilepsyDelegate__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FEpilepsyDelegate_DelegateWrapper(const FScriptDelegate& EpilepsyDelegate, bool blinkDetected)
{
	struct _Script_MultisensoryAccessibility_eventEpilepsyDelegate_Parms
	{
		bool blinkDetected;
	};
	_Script_MultisensoryAccessibility_eventEpilepsyDelegate_Parms Parms;
	Parms.blinkDetected=blinkDetected ? true : false;
	EpilepsyDelegate.ProcessDelegate<UObject>(&Parms);
}
// End Delegate FEpilepsyDelegate

// Begin Class AMultisensoryAccessibilityEpilepsy Function CallbackEpilepsy
struct Z_Construct_UFunction_AMultisensoryAccessibilityEpilepsy_CallbackEpilepsy_Statics
{
	struct MultisensoryAccessibilityEpilepsy_eventCallbackEpilepsy_Parms
	{
		FScriptDelegate callback;
		bool blinkDetected;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityEpilepsy.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_callback;
	static void NewProp_blinkDetected_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_blinkDetected;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_AMultisensoryAccessibilityEpilepsy_CallbackEpilepsy_Statics::NewProp_callback = { "callback", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MultisensoryAccessibilityEpilepsy_eventCallbackEpilepsy_Parms, callback), Z_Construct_UDelegateFunction_MultisensoryAccessibility_EpilepsyDelegate__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 43673249
void Z_Construct_UFunction_AMultisensoryAccessibilityEpilepsy_CallbackEpilepsy_Statics::NewProp_blinkDetected_SetBit(void* Obj)
{
	((MultisensoryAccessibilityEpilepsy_eventCallbackEpilepsy_Parms*)Obj)->blinkDetected = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMultisensoryAccessibilityEpilepsy_CallbackEpilepsy_Statics::NewProp_blinkDetected = { "blinkDetected", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MultisensoryAccessibilityEpilepsy_eventCallbackEpilepsy_Parms), &Z_Construct_UFunction_AMultisensoryAccessibilityEpilepsy_CallbackEpilepsy_Statics::NewProp_blinkDetected_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMultisensoryAccessibilityEpilepsy_CallbackEpilepsy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMultisensoryAccessibilityEpilepsy_CallbackEpilepsy_Statics::NewProp_callback,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMultisensoryAccessibilityEpilepsy_CallbackEpilepsy_Statics::NewProp_blinkDetected,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMultisensoryAccessibilityEpilepsy_CallbackEpilepsy_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMultisensoryAccessibilityEpilepsy_CallbackEpilepsy_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy, nullptr, "CallbackEpilepsy", nullptr, nullptr, Z_Construct_UFunction_AMultisensoryAccessibilityEpilepsy_CallbackEpilepsy_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMultisensoryAccessibilityEpilepsy_CallbackEpilepsy_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMultisensoryAccessibilityEpilepsy_CallbackEpilepsy_Statics::MultisensoryAccessibilityEpilepsy_eventCallbackEpilepsy_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMultisensoryAccessibilityEpilepsy_CallbackEpilepsy_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMultisensoryAccessibilityEpilepsy_CallbackEpilepsy_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMultisensoryAccessibilityEpilepsy_CallbackEpilepsy_Statics::MultisensoryAccessibilityEpilepsy_eventCallbackEpilepsy_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMultisensoryAccessibilityEpilepsy_CallbackEpilepsy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMultisensoryAccessibilityEpilepsy_CallbackEpilepsy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMultisensoryAccessibilityEpilepsy::execCallbackEpilepsy)
{
	P_GET_PROPERTY(FDelegateProperty,Z_Param_callback);
	P_GET_UBOOL(Z_Param_blinkDetected);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->CallbackEpilepsy(FEpilepsyDelegate(Z_Param_callback),Z_Param_blinkDetected);
	P_NATIVE_END;
}
// End Class AMultisensoryAccessibilityEpilepsy Function CallbackEpilepsy

// Begin Class AMultisensoryAccessibilityEpilepsy
void AMultisensoryAccessibilityEpilepsy::StaticRegisterNativesAMultisensoryAccessibilityEpilepsy()
{
	UClass* Class = AMultisensoryAccessibilityEpilepsy::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CallbackEpilepsy", &AMultisensoryAccessibilityEpilepsy::execCallbackEpilepsy },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMultisensoryAccessibilityEpilepsy);
UClass* Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_NoRegister()
{
	return AMultisensoryAccessibilityEpilepsy::StaticClass();
}
struct Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "MultisensoryAccessibilityEpilepsy.h" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityEpilepsy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_resolutionX_MetaData[] = {
		{ "Category", "Output Information" },
		{ "ClampMax", "4096" },
		{ "ClampMin", "32" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityEpilepsy.h" },
		{ "UIMax", "4096" },
		{ "UIMin", "32" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_resolutionY_MetaData[] = {
		{ "Category", "Output Information" },
		{ "ClampMax", "4096" },
		{ "ClampMin", "32" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityEpilepsy.h" },
		{ "UIMax", "4096" },
		{ "UIMin", "32" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_field_of_view_MetaData[] = {
		{ "Category", "Output Information" },
		{ "ClampMax", "179.9" },
		{ "ClampMin", "20.0" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityEpilepsy.h" },
		{ "UIMax", "179.9" },
		{ "UIMin", "20.0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_sceneCapture_MetaData[] = {
		{ "Category", "Output Information" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityEpilepsy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_cameraActor_MetaData[] = {
		{ "Category", "Input Information" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityEpilepsy.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_maxBlinksPerSecond_MetaData[] = {
		{ "Category", "Output Information" },
		{ "ClampMax", "60" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityEpilepsy.h" },
		{ "UIMax", "60" },
		{ "UIMin", "0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_screenFragmentToCheck_MetaData[] = {
		{ "Category", "Output Information" },
		{ "ClampMax", "100" },
		{ "ClampMin", "1" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityEpilepsy.h" },
		{ "UIMax", "100" },
		{ "UIMin", "1" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_maxColorDistance_MetaData[] = {
		{ "Category", "Output Information" },
		{ "ClampMax", "400" },
		{ "ClampMin", "0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// 1 is the whole screen, 5 is a fifth (default), meaning, if a blink happens in 1/5 of all pixels, it triggers the detection\n" },
#endif
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityEpilepsy.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "1 is the whole screen, 5 is a fifth (default), meaning, if a blink happens in 1/5 of all pixels, it triggers the detection" },
#endif
		{ "UIMax", "400" },
		{ "UIMin", "0" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_maxLuminanceDistance_MetaData[] = {
		{ "Category", "Output Information" },
		{ "ClampMax", "100" },
		{ "ClampMin", "0" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityEpilepsy.h" },
		{ "UIMax", "100" },
		{ "UIMin", "0" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FUInt32PropertyParams NewProp_resolutionX;
	static const UECodeGen_Private::FUInt32PropertyParams NewProp_resolutionY;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_field_of_view;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_sceneCapture;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_cameraActor;
	static const UECodeGen_Private::FUInt32PropertyParams NewProp_maxBlinksPerSecond;
	static const UECodeGen_Private::FUInt32PropertyParams NewProp_screenFragmentToCheck;
	static const UECodeGen_Private::FIntPropertyParams NewProp_maxColorDistance;
	static const UECodeGen_Private::FIntPropertyParams NewProp_maxLuminanceDistance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMultisensoryAccessibilityEpilepsy_CallbackEpilepsy, "CallbackEpilepsy" }, // 1623572092
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMultisensoryAccessibilityEpilepsy>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::NewProp_resolutionX = { "resolutionX", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMultisensoryAccessibilityEpilepsy, resolutionX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_resolutionX_MetaData), NewProp_resolutionX_MetaData) };
const UECodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::NewProp_resolutionY = { "resolutionY", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMultisensoryAccessibilityEpilepsy, resolutionY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_resolutionY_MetaData), NewProp_resolutionY_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::NewProp_field_of_view = { "field_of_view", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMultisensoryAccessibilityEpilepsy, field_of_view), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_field_of_view_MetaData), NewProp_field_of_view_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::NewProp_sceneCapture = { "sceneCapture", nullptr, (EPropertyFlags)0x0010000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMultisensoryAccessibilityEpilepsy, sceneCapture), Z_Construct_UClass_USceneCaptureComponent2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_sceneCapture_MetaData), NewProp_sceneCapture_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::NewProp_cameraActor = { "cameraActor", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMultisensoryAccessibilityEpilepsy, cameraActor), Z_Construct_UClass_ACameraActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_cameraActor_MetaData), NewProp_cameraActor_MetaData) };
const UECodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::NewProp_maxBlinksPerSecond = { "maxBlinksPerSecond", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMultisensoryAccessibilityEpilepsy, maxBlinksPerSecond), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_maxBlinksPerSecond_MetaData), NewProp_maxBlinksPerSecond_MetaData) };
const UECodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::NewProp_screenFragmentToCheck = { "screenFragmentToCheck", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMultisensoryAccessibilityEpilepsy, screenFragmentToCheck), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_screenFragmentToCheck_MetaData), NewProp_screenFragmentToCheck_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::NewProp_maxColorDistance = { "maxColorDistance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMultisensoryAccessibilityEpilepsy, maxColorDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_maxColorDistance_MetaData), NewProp_maxColorDistance_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::NewProp_maxLuminanceDistance = { "maxLuminanceDistance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMultisensoryAccessibilityEpilepsy, maxLuminanceDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_maxLuminanceDistance_MetaData), NewProp_maxLuminanceDistance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::NewProp_resolutionX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::NewProp_resolutionY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::NewProp_field_of_view,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::NewProp_sceneCapture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::NewProp_cameraActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::NewProp_maxBlinksPerSecond,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::NewProp_screenFragmentToCheck,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::NewProp_maxColorDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::NewProp_maxLuminanceDistance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_MultisensoryAccessibility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::ClassParams = {
	&AMultisensoryAccessibilityEpilepsy::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::PropPointers),
	0,
	0x008000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::Class_MetaDataParams), Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy()
{
	if (!Z_Registration_Info_UClass_AMultisensoryAccessibilityEpilepsy.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMultisensoryAccessibilityEpilepsy.OuterSingleton, Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMultisensoryAccessibilityEpilepsy.OuterSingleton;
}
template<> MULTISENSORYACCESSIBILITY_API UClass* StaticClass<AMultisensoryAccessibilityEpilepsy>()
{
	return AMultisensoryAccessibilityEpilepsy::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMultisensoryAccessibilityEpilepsy);
AMultisensoryAccessibilityEpilepsy::~AMultisensoryAccessibilityEpilepsy() {}
// End Class AMultisensoryAccessibilityEpilepsy

// Begin Registration
struct Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityEpilepsy_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMultisensoryAccessibilityEpilepsy, AMultisensoryAccessibilityEpilepsy::StaticClass, TEXT("AMultisensoryAccessibilityEpilepsy"), &Z_Registration_Info_UClass_AMultisensoryAccessibilityEpilepsy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMultisensoryAccessibilityEpilepsy), 1733881152U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityEpilepsy_h_1145903869(TEXT("/Script/MultisensoryAccessibility"),
	Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityEpilepsy_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityEpilepsy_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
