// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultisensoryAccessibility.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "Logging/LogMacros.h"
#include "Misc/Paths.h" // include this!

#define LOCTEXT_NAMESPACE "FMultisensoryAccessibilityModule"

//void FMultisensoryAccessibilityModule::StartupModule()
//{
//	FString ShaderDirectory = FPaths::Combine(FPaths::ProjectDir(), TEXT("Shaders")); 
//	UE_LOG(LogTemp, Warning, TEXT("This is the ShaderDirectory: %s"), *FString(ShaderDirectory));	
//	AddShaderSourceDirectoryMapping("/Project", ShaderDirectory);
// #if WITH_EDITOR

// #endif // #if WITH_EDITOR
//}

//void FMultisensoryAccessibilityModule::ShutdownModule()
//{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
//}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMultisensoryAccessibilityModule, MultisensoryAccessibility) // Eso rompe algo???
// #if WITH_EDITOR
// IMPLEMENT_PRIMARY_GAME_MODULE(FMultisensoryAccessibilityModule, Project, "Project"); // edit this!
// #else
// IMPLEMENT_MODULE(FMultisensoryAccessibilityModule, MultisensoryAccessibility)
// #endif // #if WITH_EDITOR
// pueda apuntar a ush en el plugin https://viclw17.github.io/2022/02/01/unreal-engine-custom-node