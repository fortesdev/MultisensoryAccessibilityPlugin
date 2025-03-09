// Copyright Epic Games, Inc. All Rights Reserved.

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
#endif // #if WITH_EDITOR

#define LOCTEXT_NAMESPACE "FMultisensoryAccessibilityModule"

 AMultisensoryAccessibilityPPVolume::AMultisensoryAccessibilityPPVolume()
 {
    // Class mostly used for identifying the volume among others
 }

 AMultisensoryAccessibilityPPVolume* AMultisensoryAccessibilityPPVolume::getOrCreateVolume() 
{
	/*
	1 - Se espera que el desarrollador proporcione un volumen desde BP
	2 - Si no lo ha hecho, buscamos en el mundo
	3 - Si no lo encontramos, crearemos uno, pero esto es solo en debugging, en packaging no es posible (debemos informar en documentacion)
	*/
	UWorld* world = GEngine->GameViewport->GetWorld();
	AMultisensoryAccessibilityPPVolume* _postProcessVolume = nullptr;
	for (TActorIterator<AMultisensoryAccessibilityPPVolume> ActorItr(world); ActorItr; ++ActorItr)
 	{
 	 		_postProcessVolume = Cast<AMultisensoryAccessibilityPPVolume>(*ActorItr);
 	 		break;
	}

	#if WITH_EDITOR //No es posible usar Geditor y Factories en produccion
	if (_postProcessVolume == nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("AMultisensoryAccessibilityPPVolume not found - creating new one"));	
		// https://forums.unrealengine.com/t/can-i-instantiate-volumes-through-code/281918/5
		/* Explanation of the code bellow:
			first you get uobject that represent PP asset;
			then you get factory to construct it;
			finally you use that factory to create your final actor!
		*/
		 UObject* PostProcessVolumeObj = FindObject<UObject>(nullptr, TEXT("/Script/Engine.PostProcessVolume"));
		 UActorFactory* PostProcessVolumeFactory = GEditor->FindActorFactoryByClassForActorClass(UActorFactoryBoxVolume::StaticClass(), AMultisensoryAccessibilityPPVolume::StaticClass());
		 _postProcessVolume = Cast<AMultisensoryAccessibilityPPVolume>(PostProcessVolumeFactory->CreateActor(PostProcessVolumeObj, world->PersistentLevel, FTransform()));
		 _postProcessVolume->bUnbound = 1; // queremos que el volumen ocupe/se aplique todo el nivel	
	}
	#endif // #if WITH_EDITOR

	return _postProcessVolume;
}

void AMultisensoryAccessibilityPPVolume::setMaterial(UMaterial *aMaterial, float intensity) {
   UMaterialInstanceDynamic* DynamicMaterialInstance = UMaterialInstanceDynamic::Create(aMaterial, nullptr);
	FWeightedBlendable NewBlendable; 
	NewBlendable.Object = DynamicMaterialInstance; 
	NewBlendable.Weight = 1.0;
	TScriptInterface<IBlendableInterface> BlendableInterface; 
	BlendableInterface.SetObject(NewBlendable.Object); 
	BlendableInterface.SetInterface(Cast<IBlendableInterface>(NewBlendable.Object));
	this->AddOrUpdateBlendable(BlendableInterface, intensity);
}