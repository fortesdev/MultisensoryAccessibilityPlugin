// Some copyright should be here...

using UnrealBuildTool;

public class MultisensoryAccessibility : ModuleRules
{
	public MultisensoryAccessibility(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
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
             // "ShaderCore",
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
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		if (Target.bBuildEditor)
		{
		    PrivateDependencyModuleNames.AddRange(new string[]{"UnrealEd", "MaterialEditor"}); // OJO Estas son dependencias para acceder a los operadores de actores/PP, etc.
		} // Necesitan incluirse solo cuando esta presente el editor porque si no fallaria el packaging para production

		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
