// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MultisensoryAccessibility/Public/MultisensoryAccessibilityAudioComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMultisensoryAccessibilityAudioComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UAudioComponent();
MULTISENSORYACCESSIBILITY_API UClass* Z_Construct_UClass_UMultisensoryAccessibilityAudioComponent();
MULTISENSORYACCESSIBILITY_API UClass* Z_Construct_UClass_UMultisensoryAccessibilityAudioComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_MultisensoryAccessibility();
// End Cross Module References

// Begin Class UMultisensoryAccessibilityAudioComponent Function updateSubtitles
struct Z_Construct_UFunction_UMultisensoryAccessibilityAudioComponent_updateSubtitles_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MultisensoryAccessibilitySound" },
		{ "DisplayName", "Update location based subtitles" },
		{ "Keywords", "MultisensoryAccessibility|Sound" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityAudioComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMultisensoryAccessibilityAudioComponent_updateSubtitles_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMultisensoryAccessibilityAudioComponent, nullptr, "updateSubtitles", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMultisensoryAccessibilityAudioComponent_updateSubtitles_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMultisensoryAccessibilityAudioComponent_updateSubtitles_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UMultisensoryAccessibilityAudioComponent_updateSubtitles()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMultisensoryAccessibilityAudioComponent_updateSubtitles_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMultisensoryAccessibilityAudioComponent::execupdateSubtitles)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->updateSubtitles();
	P_NATIVE_END;
}
// End Class UMultisensoryAccessibilityAudioComponent Function updateSubtitles

// Begin Class UMultisensoryAccessibilityAudioComponent
void UMultisensoryAccessibilityAudioComponent::StaticRegisterNativesUMultisensoryAccessibilityAudioComponent()
{
	UClass* Class = UMultisensoryAccessibilityAudioComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "updateSubtitles", &UMultisensoryAccessibilityAudioComponent::execupdateSubtitles },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMultisensoryAccessibilityAudioComponent);
UClass* Z_Construct_UClass_UMultisensoryAccessibilityAudioComponent_NoRegister()
{
	return UMultisensoryAccessibilityAudioComponent::StaticClass();
}
struct Z_Construct_UClass_UMultisensoryAccessibilityAudioComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "MultisensoryAccessibility" },
		{ "HideCategories", "Object ActorComponent Physics Rendering Mobility LOD PhysicsVolume" },
		{ "IncludePath", "MultisensoryAccessibilityAudioComponent.h" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityAudioComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ccLocalisedDescriptions_MetaData[] = {
		{ "Category", "Output Information" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityAudioComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ccLocalisedDescriptions;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMultisensoryAccessibilityAudioComponent_updateSubtitles, "updateSubtitles" }, // 1789327306
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMultisensoryAccessibilityAudioComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UMultisensoryAccessibilityAudioComponent_Statics::NewProp_ccLocalisedDescriptions = { "ccLocalisedDescriptions", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMultisensoryAccessibilityAudioComponent, ccLocalisedDescriptions), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ccLocalisedDescriptions_MetaData), NewProp_ccLocalisedDescriptions_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMultisensoryAccessibilityAudioComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMultisensoryAccessibilityAudioComponent_Statics::NewProp_ccLocalisedDescriptions,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMultisensoryAccessibilityAudioComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UMultisensoryAccessibilityAudioComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAudioComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_MultisensoryAccessibility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMultisensoryAccessibilityAudioComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMultisensoryAccessibilityAudioComponent_Statics::ClassParams = {
	&UMultisensoryAccessibilityAudioComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UMultisensoryAccessibilityAudioComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UMultisensoryAccessibilityAudioComponent_Statics::PropPointers),
	0,
	0x00A000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMultisensoryAccessibilityAudioComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UMultisensoryAccessibilityAudioComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMultisensoryAccessibilityAudioComponent()
{
	if (!Z_Registration_Info_UClass_UMultisensoryAccessibilityAudioComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMultisensoryAccessibilityAudioComponent.OuterSingleton, Z_Construct_UClass_UMultisensoryAccessibilityAudioComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMultisensoryAccessibilityAudioComponent.OuterSingleton;
}
template<> MULTISENSORYACCESSIBILITY_API UClass* StaticClass<UMultisensoryAccessibilityAudioComponent>()
{
	return UMultisensoryAccessibilityAudioComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMultisensoryAccessibilityAudioComponent);
UMultisensoryAccessibilityAudioComponent::~UMultisensoryAccessibilityAudioComponent() {}
// End Class UMultisensoryAccessibilityAudioComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityAudioComponent_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMultisensoryAccessibilityAudioComponent, UMultisensoryAccessibilityAudioComponent::StaticClass, TEXT("UMultisensoryAccessibilityAudioComponent"), &Z_Registration_Info_UClass_UMultisensoryAccessibilityAudioComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMultisensoryAccessibilityAudioComponent), 1764492302U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityAudioComponent_h_4190287267(TEXT("/Script/MultisensoryAccessibility"),
	Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityAudioComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityAudioComponent_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
