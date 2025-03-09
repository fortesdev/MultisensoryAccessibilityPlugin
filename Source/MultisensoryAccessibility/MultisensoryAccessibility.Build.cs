/* 
	Multi-sensory Accessibility Plugin for UE5
 	Copyright 2025, Francisco Fortes

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at: http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and limitations under the License.
*/

using UnrealBuildTool;

public class MultisensoryAccessibility : ModuleRules
{
	public MultisensoryAccessibility(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ...	
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
             	"RenderCore",
             	"InputCore",
             	"Engine",
	     		"UMG",
             	"RHI",
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"Projects",
				"RenderCore",
				"UMG",
				// ... 	
			}
			);
		
		if (Target.bBuildEditor)
		{
			// Modules forbidden in production/packaging
		    PrivateDependencyModuleNames.AddRange(new string[]{"UnrealEd", "MaterialEditor"}); 
		} 

		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... 
			}
			);
	}
}
