
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

#include "CoreMinimal.h"
#include "Components/AudioComponent.h"
#include "MultisensoryAccessibilityAudioComponent.generated.h"

UCLASS(ClassGroup=MultisensoryAccessibility, meta=(BlueprintSpawnableComponent)) // allows adding it as spawnable actor component
class UMultisensoryAccessibilityAudioComponent : public UAudioComponent
{
	GENERATED_BODY()

public:
	UMultisensoryAccessibilityAudioComponent();

	UFUNCTION(BlueprintCallable, 
			meta = (DisplayName = "Update location based subtitles", 
			Keywords = "MultisensoryAccessibility|Sound"),
			Category = "MultisensoryAccessibilitySound")
		void updateSubtitles();

	UFUNCTION(BlueprintCallable, 
			meta = (DisplayName = "Change subtitles file", 
			Keywords = "MultisensoryAccessibility|Sound"),
			Category = "MultisensoryAccessibilitySound")
		void changeSubtitlesFile(FString newFile);

    UPROPERTY(EditAnywhere, Category = "Output Information")
    	FString ccLocalisedDescriptions = ANSI_TO_TCHAR("positionsCCSubtitlesEN.srt");

    UPROPERTY(EditAnywhere, Category = "Output Information")
		bool isObservedInFirstPerson = false;
		
private:
	FText getLocationText(FVector posVector, FVector playerLocation, FVector actorLocation);
	int16 deltaPosChange(FVector playerLocation, FVector emiterLocation);
	FText appendFormatted(FText currentText, FText newText, FText separator);
	
	const int16 kDistanceThreshold = 100;
    int32 startingMeasurementMs = 200;
	FVector previousPosVector;
	int16 previousDistance = 0;
	FText getLocationBasedSubtitlesText();
	void preloadConstants();
	int16 relativePos(int16 coord);

	FString ccGettingCloser = ANSI_TO_TCHAR("getting closer");
	FString ccMovingAway = ANSI_TO_TCHAR("moving away");
	FString ccFromTheLeft = ANSI_TO_TCHAR("from the left");
	FString ccFromTheRight = ANSI_TO_TCHAR("from the right");
	FString ccAhead = ANSI_TO_TCHAR("ahead");
	FString ccBehind = ANSI_TO_TCHAR("behind");
	FString ccAbove = ANSI_TO_TCHAR("above");
	FString ccBellow = ANSI_TO_TCHAR("bellow");

	friend class FAudioTest;
};


