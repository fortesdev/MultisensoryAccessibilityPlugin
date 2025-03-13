// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MultisensoryAccessibilityTextBlock.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MULTISENSORYACCESSIBILITY_MultisensoryAccessibilityTextBlock_generated_h
#error "MultisensoryAccessibilityTextBlock.generated.h already included, missing '#pragma once' in MultisensoryAccessibilityTextBlock.h"
#endif
#define MULTISENSORYACCESSIBILITY_MultisensoryAccessibilityTextBlock_generated_h

#define FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h_19_DELEGATE \
MULTISENSORYACCESSIBILITY_API void FSubtitleReceivedSignature_DelegateWrapper(const FMulticastScriptDelegate& SubtitleReceivedSignature, FText const& SubtitleText);


#define FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execUpdateSubtitleText);


#define FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h_24_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	MULTISENSORYACCESSIBILITY_API UUOMultisensoryAccessibilityDSubtitleInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UUOMultisensoryAccessibilityDSubtitleInterface(UUOMultisensoryAccessibilityDSubtitleInterface&&); \
	UUOMultisensoryAccessibilityDSubtitleInterface(const UUOMultisensoryAccessibilityDSubtitleInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(MULTISENSORYACCESSIBILITY_API, UUOMultisensoryAccessibilityDSubtitleInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUOMultisensoryAccessibilityDSubtitleInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUOMultisensoryAccessibilityDSubtitleInterface) \
	MULTISENSORYACCESSIBILITY_API virtual ~UUOMultisensoryAccessibilityDSubtitleInterface();


#define FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h_24_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUUOMultisensoryAccessibilityDSubtitleInterface(); \
	friend struct Z_Construct_UClass_UUOMultisensoryAccessibilityDSubtitleInterface_Statics; \
public: \
	DECLARE_CLASS(UUOMultisensoryAccessibilityDSubtitleInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/MultisensoryAccessibility"), MULTISENSORYACCESSIBILITY_API) \
	DECLARE_SERIALIZER(UUOMultisensoryAccessibilityDSubtitleInterface)


#define FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h_24_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h_24_GENERATED_UINTERFACE_BODY() \
	FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h_24_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h_24_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IUOMultisensoryAccessibilityDSubtitleInterface() {} \
public: \
	typedef UUOMultisensoryAccessibilityDSubtitleInterface UClassType; \
	typedef IUOMultisensoryAccessibilityDSubtitleInterface ThisClass; \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h_21_PROLOG
#define FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h_24_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MULTISENSORYACCESSIBILITY_API UClass* StaticClass<class UUOMultisensoryAccessibilityDSubtitleInterface>();

#define FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h_45_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMultisensoryAccessibilityTextBlock(); \
	friend struct Z_Construct_UClass_UMultisensoryAccessibilityTextBlock_Statics; \
public: \
	DECLARE_CLASS(UMultisensoryAccessibilityTextBlock, UTextBlock, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MultisensoryAccessibility"), NO_API) \
	DECLARE_SERIALIZER(UMultisensoryAccessibilityTextBlock) \
	virtual UObject* _getUObject() const override { return const_cast<UMultisensoryAccessibilityTextBlock*>(this); }


#define FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h_45_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMultisensoryAccessibilityTextBlock(UMultisensoryAccessibilityTextBlock&&); \
	UMultisensoryAccessibilityTextBlock(const UMultisensoryAccessibilityTextBlock&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMultisensoryAccessibilityTextBlock); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMultisensoryAccessibilityTextBlock); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMultisensoryAccessibilityTextBlock) \
	NO_API virtual ~UMultisensoryAccessibilityTextBlock();


#define FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h_42_PROLOG
#define FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h_45_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h_45_INCLASS_NO_PURE_DECLS \
	FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h_45_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MULTISENSORYACCESSIBILITY_API UClass* StaticClass<class UMultisensoryAccessibilityTextBlock>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_MyProject2_Plugins_MultisensoryAccessibility_Source_MultisensoryAccessibility_Public_MultisensoryAccessibilityTextBlock_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
