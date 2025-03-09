

#pragma once

#include "CoreMinimal.h"
//#include "UObject/Interface.h"
#include "Components/AudioComponent.h"
#include "MultisensoryAccessibilityAudioComponent.generated.h"

UCLASS(ClassGroup=MultisensoryAccessibility, meta=(BlueprintSpawnableComponent)) // BlueprintSpawnableComponent permite que pueda incorporarse como actor component
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

    UPROPERTY(EditAnywhere, Category = "Output Information")
    	FString ccLocalisedDescriptions = ANSI_TO_TCHAR("positionsCCSubtitlesEN.srt");

private:
	const int16 kDistanceThreshold = 100;
    int32 startingMeasurementMs = 200;
	FVector previousPosVector;
	int16 previousDistance = 0;
	FText getLocationBasedSubtitlesText();
	void preloadConstants();
	int16 relativePos(int16 coord);
	int16 deltaPosChange(FVector actorLocation);
	FText appendFormatted(FText currentText, FText newText, FText separator);

	FString ccGettingCloser = ANSI_TO_TCHAR("getting closer");
	FString ccMovingAway = ANSI_TO_TCHAR("moving away");
	FString ccFromTheLeft = ANSI_TO_TCHAR("from the left");
	FString ccFromTheRight = ANSI_TO_TCHAR("from the right");
	FString ccAhead = ANSI_TO_TCHAR("ahead");
	FString ccBehind = ANSI_TO_TCHAR("behind");
	FString ccAbove = ANSI_TO_TCHAR("above");
	FString ccBellow = ANSI_TO_TCHAR("bellow");
};

