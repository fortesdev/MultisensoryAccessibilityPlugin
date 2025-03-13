// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MultisensoryAccessibility/Public/MultisensoryAccessibilityPPVolume.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMultisensoryAccessibilityPPVolume() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APostProcessVolume();
MULTISENSORYACCESSIBILITY_API UClass* Z_Construct_UClass_AMultisensoryAccessibilityPPVolume();
MULTISENSORYACCESSIBILITY_API UClass* Z_Construct_UClass_AMultisensoryAccessibilityPPVolume_NoRegister();
UPackage* Z_Construct_UPackage__Script_MultisensoryAccessibility();
// End Cross Module References

// Begin Class AMultisensoryAccessibilityPPVolume
void AMultisensoryAccessibilityPPVolume::StaticRegisterNativesAMultisensoryAccessibilityPPVolume()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMultisensoryAccessibilityPPVolume);
UClass* Z_Construct_UClass_AMultisensoryAccessibilityPPVolume_NoRegister()
{
	return AMultisensoryAccessibilityPPVolume::StaticClass();
}
struct Z_Construct_UClass_AMultisensoryAccessibilityPPVolume_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "AutoExpandCategories", "PostProcessVolume" },
		{ "HideCategories", "Advanced Collision Volume Brush Attachment Brush Physics Object Blueprint Display Rendering Physics Input" },
		{ "IncludePath", "MultisensoryAccessibilityPPVolume.h" },
		{ "ModuleRelativePath", "Public/MultisensoryAccessibilityPPVolume.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMultisensoryAccessibilityPPVolume>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AMultisensoryAccessibilityPPVolume_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APostProcessVolume,
	(UObject* (*)())Z_Construct_UPackage__Script_MultisensoryAccessibility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMultisensoryAccessibilityPPVolume_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMultisensoryAccessibilityPPVolume_Statics::ClassParams = {
	&AMultisensoryAccessibilityPPVolume::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMultisensoryAccessibilityPPVolume_Statics::Class_MetaDataParams), Z_Construct_UClass_AMultisensoryAccessibilityPPVolume_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMultisensoryAccessibilityPPVolume()
{
	if (!Z_Registration_Info_UClass_AMultisensoryAccessibilityPPVolume.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMultisensoryAccessibilityPPVolume.OuterSingleton, Z_Construct_UClass_AMultisensoryAccessibilityPPVolume_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMultisensoryAccessibilityPPVolume.OuterSingleton;
}
template<> MULTISENSORYACCESSIBILITY_API UClass* StaticClass<AMultisensoryAccessibilityPPVolume>()
{
	return AMultisensoryAccessibilityPPVolume::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMultisensoryAccessibilityPPVolume);
AMultisensoryAccessibilityPPVolume::~AMultisensoryAccessibilityPPVolume() {}
// End Class AMultisensoryAccessibilityPPVolume

// Begin Registration
struct Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityPPVolume_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMultisensoryAccessibilityPPVolume, AMultisensoryAccessibilityPPVolume::StaticClass, TEXT("AMultisensoryAccessibilityPPVolume"), &Z_Registration_Info_UClass_AMultisensoryAccessibilityPPVolume, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMultisensoryAccessibilityPPVolume), 1317160895U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityPPVolume_h_3298696743(TEXT("/Script/MultisensoryAccessibility"),
	Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityPPVolume_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityPPVolume_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
