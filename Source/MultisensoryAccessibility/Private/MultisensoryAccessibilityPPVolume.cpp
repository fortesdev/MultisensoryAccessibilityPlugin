/* 
	Multi-sensory Accessibility Plugin for UE5
 	Copyright 2025, Francisco Fortes

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at: http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and limitations under the License.
*/

#include "MultisensoryAccessibilityPPVolume.h"
#include "Engine.h"
#include "Logging/StructuredLog.h"
#include "MultisensoryAccessibilityPPVolume.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "UObject/UnrealType.h"
#include <string>
#include "Materials/MaterialExpression.h"
#if WITH_EDITOR
   #include "ActorFactories/ActorFactory.h"
   #include "ActorFactories/ActorFactoryBoxVolume.h"
   #include "Editor.h"
   #include "Debugging/SKismetDebugTreeView.h"
   #include "Editor/EditorEngine.h"
#endif

#define LOCTEXT_NAMESPACE "FMultisensoryAccessibilityModule"

 AMultisensoryAccessibilityPPVolume::AMultisensoryAccessibilityPPVolume()
 {
    // Class mostly used for identifying the volume among others
 }

 AMultisensoryAccessibilityPPVolume* AMultisensoryAccessibilityPPVolume::getOrCreateVolume() 
{
	UWorld* world = GEngine->GameViewport->GetWorld();
	AMultisensoryAccessibilityPPVolume* _postProcessVolume = nullptr;
	for (TActorIterator<AMultisensoryAccessibilityPPVolume> ActorItr(world); ActorItr; ++ActorItr)
 	{
 	 		_postProcessVolume = Cast<AMultisensoryAccessibilityPPVolume>(*ActorItr);
 	 		break;
	}
	// If no volume is provided, the plugin is able to create and add one to the map, but only on debugging. Do not attempt automatic creation in production
	#if WITH_EDITOR // WARNING: You are not allowed to use GEditor and Factories in production!
	if (_postProcessVolume == nullptr) 
	{
		UE_LOG(LogTemp, Warning, TEXT("AMultisensoryAccessibilityPPVolume not found - creating new one"));	
		// Explanation: first we find the UObject that represent the volume asset, then we get factory to construct it, and finally 
		// we use that factory to create the final actor.
		 UObject* PostProcessVolumeObj = FindObject<UObject>(nullptr, TEXT("/Script/Engine.PostProcessVolume"));
		 UActorFactory* PostProcessVolumeFactory = GEditor->FindActorFactoryByClassForActorClass(UActorFactoryBoxVolume::StaticClass(), AMultisensoryAccessibilityPPVolume::StaticClass());
		 _postProcessVolume = Cast<AMultisensoryAccessibilityPPVolume>(PostProcessVolumeFactory->CreateActor(PostProcessVolumeObj, world->PersistentLevel, FTransform()));
		 _postProcessVolume->bUnbound = 1; // infinite extension in the map	
	}
	#endif // #if WITH_EDITOR

	return _postProcessVolume;
}

void AMultisensoryAccessibilityPPVolume::setMaterial(UMaterial *aMaterial, float intensity) 
{
   UMaterialInstanceDynamic* DynamicMaterialInstance = UMaterialInstanceDynamic::Create(aMaterial, nullptr);
	FWeightedBlendable NewBlendable; 
	NewBlendable.Object = DynamicMaterialInstance; 
	NewBlendable.Weight = 1.0;
	TScriptInterface<IBlendableInterface> BlendableInterface; 
	BlendableInterface.SetObject(NewBlendable.Object); 
	BlendableInterface.SetInterface(Cast<IBlendableInterface>(NewBlendable.Object));
	this->AddOrUpdateBlendable(BlendableInterface, intensity);
}