/* 
	Multi-sensory Accessibility Plugin for UE5
 	Copyright 2025, Francisco Fortes

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at: http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and limitations under the License.
*/

#pragma once

#include "Modules/ModuleManager.h"
#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Misc/Paths.h"
#include "ShaderCore.h"

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
