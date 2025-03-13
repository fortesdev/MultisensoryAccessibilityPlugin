// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMultisensoryAccessibility_init() {}
	MULTISENSORYACCESSIBILITY_API UFunction* Z_Construct_UDelegateFunction_MultisensoryAccessibility_EpilepsyDelegate__DelegateSignature();
	MULTISENSORYACCESSIBILITY_API UFunction* Z_Construct_UDelegateFunction_MultisensoryAccessibility_SubtitleReceivedSignature__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_MultisensoryAccessibility;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_MultisensoryAccessibility()
	{
		if (!Z_Registration_Info_UPackage__Script_MultisensoryAccessibility.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_MultisensoryAccessibility_EpilepsyDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_MultisensoryAccessibility_SubtitleReceivedSignature__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/MultisensoryAccessibility",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x0D7F2EB5,
				0x00EF1AE6,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_MultisensoryAccessibility.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_MultisensoryAccessibility.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_MultisensoryAccessibility(Z_Construct_UPackage__Script_MultisensoryAccessibility, TEXT("/Script/MultisensoryAccessibility"), Z_Registration_Info_UPackage__Script_MultisensoryAccessibility, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x0D7F2EB5, 0x00EF1AE6));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
