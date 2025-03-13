// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MultisensoryAccessibility/Public/MultisensoryAccessibilityTextBlock.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMultisensoryAccessibilityTextBlock() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
MULTISENSORYACCESSIBILITY_API UClass* Z_Construct_UClass_UMultisensoryAccessibilityTextBlock();
MULTISENSORYACCESSIBILITY_API UClass* Z_Construct_UClass_UMultisensoryAccessibilityTextBlock_NoRegister();
MULTISENSORYACCESSIBILITY_API UClass* Z_Construct_UClass_UUOMultisensoryAccessibilityDSubtitleInterface();
MULTISENSORYACCESSIBILITY_API UClass* Z_Construct_UClass_UUOMultisensoryAccessibilityDSubtitleInterface_NoRegister();
MULTISENSORYACCESSIBILITY_API UFunction* Z_Construct_UDelegateFunction_MultisensoryAccessibility_SubtitleReceivedSignature__DelegateSignature();
UMG_API UClass* Z_Construct_UClass_UTextBlock();
UPackage* Z_Construct_UPackage__Script_MultisensoryAccessibility();
// End Cross Module References

// Begin Delegate FSubtitleReceivedSignature
struct Z_Construct_UDelegateFunction_MultisensoryAccessibility_SubtitleReceivedSignature__DelegateSignature_Statics
{
	struct _Script_MultisensoryAccessibility_eventSubtitleReceivedSignature_Parms
	{
		FText SubtitleText;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityTextBlock.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SubtitleText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FTextPropertyParams NewProp_SubtitleText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FTextPropertyParams Z_Construct_UDelegateFunction_MultisensoryAccessibility_SubtitleReceivedSignature__DelegateSignature_Statics::NewProp_SubtitleText = { "SubtitleText", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_MultisensoryAccessibility_eventSubtitleReceivedSignature_Parms, SubtitleText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SubtitleText_MetaData), NewProp_SubtitleText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_MultisensoryAccessibility_SubtitleReceivedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_MultisensoryAccessibility_SubtitleReceivedSignature__DelegateSignature_Statics::NewProp_SubtitleText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MultisensoryAccessibility_SubtitleReceivedSignature__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_MultisensoryAccessibility_SubtitleReceivedSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_MultisensoryAccessibility, nullptr, "SubtitleReceivedSignature__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_MultisensoryAccessibility_SubtitleReceivedSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MultisensoryAccessibility_SubtitleReceivedSignature__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_MultisensoryAccessibility_SubtitleReceivedSignature__DelegateSignature_Statics::_Script_MultisensoryAccessibility_eventSubtitleReceivedSignature_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_MultisensoryAccessibility_SubtitleReceivedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_MultisensoryAccessibility_SubtitleReceivedSignature__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_MultisensoryAccessibility_SubtitleReceivedSignature__DelegateSignature_Statics::_Script_MultisensoryAccessibility_eventSubtitleReceivedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_MultisensoryAccessibility_SubtitleReceivedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_MultisensoryAccessibility_SubtitleReceivedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FSubtitleReceivedSignature_DelegateWrapper(const FMulticastScriptDelegate& SubtitleReceivedSignature, FText const& SubtitleText)
{
	struct _Script_MultisensoryAccessibility_eventSubtitleReceivedSignature_Parms
	{
		FText SubtitleText;
	};
	_Script_MultisensoryAccessibility_eventSubtitleReceivedSignature_Parms Parms;
	Parms.SubtitleText=SubtitleText;
	SubtitleReceivedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FSubtitleReceivedSignature

// Begin Interface UUOMultisensoryAccessibilityDSubtitleInterface Function UpdateSubtitleText
struct Z_Construct_UFunction_UUOMultisensoryAccessibilityDSubtitleInterface_UpdateSubtitleText_Statics
{
	struct UOMultisensoryAccessibilityDSubtitleInterface_eventUpdateSubtitleText_Parms
	{
		FText SubtitleText;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SubtitleHook" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityTextBlock.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SubtitleText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FTextPropertyParams NewProp_SubtitleText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UUOMultisensoryAccessibilityDSubtitleInterface_UpdateSubtitleText_Statics::NewProp_SubtitleText = { "SubtitleText", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOMultisensoryAccessibilityDSubtitleInterface_eventUpdateSubtitleText_Parms, SubtitleText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SubtitleText_MetaData), NewProp_SubtitleText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUOMultisensoryAccessibilityDSubtitleInterface_UpdateSubtitleText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUOMultisensoryAccessibilityDSubtitleInterface_UpdateSubtitleText_Statics::NewProp_SubtitleText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUOMultisensoryAccessibilityDSubtitleInterface_UpdateSubtitleText_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUOMultisensoryAccessibilityDSubtitleInterface_UpdateSubtitleText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUOMultisensoryAccessibilityDSubtitleInterface, nullptr, "UpdateSubtitleText", nullptr, nullptr, Z_Construct_UFunction_UUOMultisensoryAccessibilityDSubtitleInterface_UpdateSubtitleText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUOMultisensoryAccessibilityDSubtitleInterface_UpdateSubtitleText_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUOMultisensoryAccessibilityDSubtitleInterface_UpdateSubtitleText_Statics::UOMultisensoryAccessibilityDSubtitleInterface_eventUpdateSubtitleText_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUOMultisensoryAccessibilityDSubtitleInterface_UpdateSubtitleText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUOMultisensoryAccessibilityDSubtitleInterface_UpdateSubtitleText_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UUOMultisensoryAccessibilityDSubtitleInterface_UpdateSubtitleText_Statics::UOMultisensoryAccessibilityDSubtitleInterface_eventUpdateSubtitleText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UUOMultisensoryAccessibilityDSubtitleInterface_UpdateSubtitleText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUOMultisensoryAccessibilityDSubtitleInterface_UpdateSubtitleText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IUOMultisensoryAccessibilityDSubtitleInterface::execUpdateSubtitleText)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_SubtitleText);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateSubtitleText(Z_Param_Out_SubtitleText);
	P_NATIVE_END;
}
// End Interface UUOMultisensoryAccessibilityDSubtitleInterface Function UpdateSubtitleText

// Begin Interface UUOMultisensoryAccessibilityDSubtitleInterface
void UUOMultisensoryAccessibilityDSubtitleInterface::StaticRegisterNativesUUOMultisensoryAccessibilityDSubtitleInterface()
{
	UClass* Class = UUOMultisensoryAccessibilityDSubtitleInterface::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "UpdateSubtitleText", &IUOMultisensoryAccessibilityDSubtitleInterface::execUpdateSubtitleText },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUOMultisensoryAccessibilityDSubtitleInterface);
UClass* Z_Construct_UClass_UUOMultisensoryAccessibilityDSubtitleInterface_NoRegister()
{
	return UUOMultisensoryAccessibilityDSubtitleInterface::StaticClass();
}
struct Z_Construct_UClass_UUOMultisensoryAccessibilityDSubtitleInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "false" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityTextBlock.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UUOMultisensoryAccessibilityDSubtitleInterface_UpdateSubtitleText, "UpdateSubtitleText" }, // 1688042288
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IUOMultisensoryAccessibilityDSubtitleInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UUOMultisensoryAccessibilityDSubtitleInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_MultisensoryAccessibility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUOMultisensoryAccessibilityDSubtitleInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UUOMultisensoryAccessibilityDSubtitleInterface_Statics::ClassParams = {
	&UUOMultisensoryAccessibilityDSubtitleInterface::StaticClass,
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
	0x000840A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUOMultisensoryAccessibilityDSubtitleInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UUOMultisensoryAccessibilityDSubtitleInterface_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UUOMultisensoryAccessibilityDSubtitleInterface()
{
	if (!Z_Registration_Info_UClass_UUOMultisensoryAccessibilityDSubtitleInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUOMultisensoryAccessibilityDSubtitleInterface.OuterSingleton, Z_Construct_UClass_UUOMultisensoryAccessibilityDSubtitleInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UUOMultisensoryAccessibilityDSubtitleInterface.OuterSingleton;
}
template<> MULTISENSORYACCESSIBILITY_API UClass* StaticClass<UUOMultisensoryAccessibilityDSubtitleInterface>()
{
	return UUOMultisensoryAccessibilityDSubtitleInterface::StaticClass();
}
UUOMultisensoryAccessibilityDSubtitleInterface::UUOMultisensoryAccessibilityDSubtitleInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UUOMultisensoryAccessibilityDSubtitleInterface);
UUOMultisensoryAccessibilityDSubtitleInterface::~UUOMultisensoryAccessibilityDSubtitleInterface() {}
// End Interface UUOMultisensoryAccessibilityDSubtitleInterface

// Begin Class UMultisensoryAccessibilityTextBlock
void UMultisensoryAccessibilityTextBlock::StaticRegisterNativesUMultisensoryAccessibilityTextBlock()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMultisensoryAccessibilityTextBlock);
UClass* Z_Construct_UClass_UMultisensoryAccessibilityTextBlock_NoRegister()
{
	return UMultisensoryAccessibilityTextBlock::StaticClass();
}
struct Z_Construct_UClass_UMultisensoryAccessibilityTextBlock_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "MultisensoryAccessibilityTextBlock.h" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityTextBlock.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSubtitleReceived_MetaData[] = {
		{ "Category", "SubtitleHook" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityTextBlock.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSubtitleReceived;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMultisensoryAccessibilityTextBlock>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UMultisensoryAccessibilityTextBlock_Statics::NewProp_OnSubtitleReceived = { "OnSubtitleReceived", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMultisensoryAccessibilityTextBlock, OnSubtitleReceived), Z_Construct_UDelegateFunction_MultisensoryAccessibility_SubtitleReceivedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSubtitleReceived_MetaData), NewProp_OnSubtitleReceived_MetaData) }; // 3694597337
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMultisensoryAccessibilityTextBlock_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMultisensoryAccessibilityTextBlock_Statics::NewProp_OnSubtitleReceived,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMultisensoryAccessibilityTextBlock_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UMultisensoryAccessibilityTextBlock_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UTextBlock,
	(UObject* (*)())Z_Construct_UPackage__Script_MultisensoryAccessibility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMultisensoryAccessibilityTextBlock_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UMultisensoryAccessibilityTextBlock_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UUOMultisensoryAccessibilityDSubtitleInterface_NoRegister, (int32)VTABLE_OFFSET(UMultisensoryAccessibilityTextBlock, IUOMultisensoryAccessibilityDSubtitleInterface), false },  // 3440621073
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMultisensoryAccessibilityTextBlock_Statics::ClassParams = {
	&UMultisensoryAccessibilityTextBlock::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UMultisensoryAccessibilityTextBlock_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UMultisensoryAccessibilityTextBlock_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00A000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMultisensoryAccessibilityTextBlock_Statics::Class_MetaDataParams), Z_Construct_UClass_UMultisensoryAccessibilityTextBlock_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMultisensoryAccessibilityTextBlock()
{
	if (!Z_Registration_Info_UClass_UMultisensoryAccessibilityTextBlock.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMultisensoryAccessibilityTextBlock.OuterSingleton, Z_Construct_UClass_UMultisensoryAccessibilityTextBlock_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMultisensoryAccessibilityTextBlock.OuterSingleton;
}
template<> MULTISENSORYACCESSIBILITY_API UClass* StaticClass<UMultisensoryAccessibilityTextBlock>()
{
	return UMultisensoryAccessibilityTextBlock::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMultisensoryAccessibilityTextBlock);
UMultisensoryAccessibilityTextBlock::~UMultisensoryAccessibilityTextBlock() {}
// End Class UMultisensoryAccessibilityTextBlock

// Begin Registration
struct Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UUOMultisensoryAccessibilityDSubtitleInterface, UUOMultisensoryAccessibilityDSubtitleInterface::StaticClass, TEXT("UUOMultisensoryAccessibilityDSubtitleInterface"), &Z_Registration_Info_UClass_UUOMultisensoryAccessibilityDSubtitleInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUOMultisensoryAccessibilityDSubtitleInterface), 3440621073U) },
		{ Z_Construct_UClass_UMultisensoryAccessibilityTextBlock, UMultisensoryAccessibilityTextBlock::StaticClass, TEXT("UMultisensoryAccessibilityTextBlock"), &Z_Registration_Info_UClass_UMultisensoryAccessibilityTextBlock, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMultisensoryAccessibilityTextBlock), 2788679995U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h_2449328414(TEXT("/Script/MultisensoryAccessibility"),
	Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
