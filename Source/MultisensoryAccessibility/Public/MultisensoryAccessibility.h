// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"
#include "CoreMinimal.h"
#include "Modules/ModuleManager.h" // include this!

class FMultisensoryAccessibilityModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override {
 		FString ShaderDirectory = FPaths::Combine(FPaths::ProjectDir(), TEXT("Plugins/MultisensoryAccessibility/Shaders")); 
 		AddShaderSourceDirectoryMapping("/Project", ShaderDirectory);
	}
	virtual void ShutdownModule() override {

	}
};
