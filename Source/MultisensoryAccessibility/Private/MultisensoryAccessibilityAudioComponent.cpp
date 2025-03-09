// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultisensoryAccessibilityAudioComponent.h"
#include "Components/AudioComponent.h"
#include "SubtitleManager.h"
#include "MultisensoryAccessibilityTextBlock.h"

#define LOCTEXT_NAMESPACE "FMultisensoryAccessibilityModule" 

UMultisensoryAccessibilityAudioComponent::UMultisensoryAccessibilityAudioComponent()
{
	preloadConstants();
}

void UMultisensoryAccessibilityAudioComponent::updateSubtitles()
{	
	int32 currentMs = FDateTime::UtcNow().GetMillisecond();
    int32 adjustedCurrentMs = currentMs >= startingMeasurementMs ? currentMs : startingMeasurementMs + currentMs;
	
	if ((adjustedCurrentMs - startingMeasurementMs) >= 200) { // 1000ms / 5 (to measure until 5 position changes per second)
		startingMeasurementMs = currentMs;
		FSubtitleCue subtitle = FSubtitleCue();
		FText someText = FText::GetEmpty();
		if (GetPlayState() == EAudioComponentPlayState::Playing) { 
		/* It is responsibility of the BP to stop this method, not for us to check the state before broadcasting:
		 the reason is, we need to send empty once stops playing */
			someText = getLocationBasedSubtitlesText();
		} 

		if (FSubtitleManager* subtitleManager = FSubtitleManager::GetSubtitleManager())
		{
			FString SomeString = someText.ToString();
			subtitleManager->OnSetSubtitleText().Broadcast(someText);
		}	
	 }	
}

FText UMultisensoryAccessibilityAudioComponent::getLocationBasedSubtitlesText() 
{
	AActor* parentActor = GetOwner();
	APlayerController* player = GetWorld()->GetFirstPlayerController();
	FVector posVector;
	FText locationText = FText::GetEmpty();
	if (parentActor && player)
	{
		FVector actorLocation = parentActor->GetActorLocation();
		// We should not compare the inverse transform position between actor and player, but against the player's camera, 
		// as its vector will change the relative positions
		APlayerCameraManager* PlayerCamera = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;
		posVector = PlayerCamera->GetActorTransform().InverseTransformPosition(actorLocation);
		int xPos = relativePos(posVector.X);
		int yPos = relativePos(posVector.Y);
		int zPos = relativePos(posVector.Z);
		int direction = deltaPosChange(actorLocation);
		FString emptyString = ANSI_TO_TCHAR("");
		FString commaString = ANSI_TO_TCHAR(",");
		FString directionString = direction > 0 ? ccMovingAway : direction < 0 ? ccGettingCloser : emptyString;
		FString zString = zPos > 0 ? ccAbove : zPos < 0 ? ccBellow : emptyString;
		FString yString = yPos > 0 ? ccFromTheRight : yPos < 0 ? ccFromTheLeft : emptyString;
		FString xString = xPos > 0 ? ccAhead : xPos < 0 ? ccBehind : emptyString;
		// Format: "Actor_Subtitle {getting closer/moving away} {ahead/behind}, {bellow/above} {from the right/left}" 		
		if (direction != 0) {
			locationText = FText::FromString(directionString);
		}
		locationText = appendFormatted(locationText, FText::FromString(xString), FText::FromString(emptyString));
		locationText = appendFormatted(locationText, FText::FromString(zString), FText::FromString(commaString));
		locationText = appendFormatted(locationText, FText::FromString(yString), FText::FromString(emptyString));	
		//UE_LOG(LogClass, Log, TEXT("posVector: %s, %d:%d:%d(%d) => %s"), *posVector.ToString(), xPos, yPos, zPos, direction, *locationText.ToString());
		previousPosVector = posVector;
	}
	return locationText;
}

FText UMultisensoryAccessibilityAudioComponent::appendFormatted(FText currentText, FText newText, FText separator) {
	return currentText.ToString().Len() == 0 ? newText :
		newText.ToString().Len() == 0 ? currentText :
		FText::Format(LOCTEXT("Subtitle", "{0}{1} {2}"), currentText, separator, newText);
}

int16 UMultisensoryAccessibilityAudioComponent::relativePos(int16 coord) {
	/* This method returns, for a given coordinate, if the other object is in relative positive position (front, bellow, to the right), viceversa, 
	or too small of different to tell (compared to the threshold constant), in which case the value returned is zero. */
	return coord > kDistanceThreshold ? 1 : 
		   coord < -kDistanceThreshold ? -1 : 0;
}

int16 UMultisensoryAccessibilityAudioComponent::deltaPosChange(FVector actorLocation) {
	FVector playerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	int16 newDistance = FVector::Dist(playerLocation, actorLocation);
	int16 difference = newDistance - previousDistance;
	previousDistance = newDistance;
	return relativePos(difference);
}

void UMultisensoryAccessibilityAudioComponent::preloadConstants() {
	FString file = FPaths::ProjectContentDir();
	file.Append(ccLocalisedDescriptions);//TEXT("positionsCCSubtitlesEN.srt"));
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	FString Content;
	if (FileManager.FileExists(*file)) {
	    if(FFileHelper::LoadFileToString(Content ,*file, FFileHelper::EHashOptions::None))
	    {
			TArray<FString>* SrtLines = new TArray<FString>();
			Content.ParseIntoArrayLines(*SrtLines, false);
			auto It = SrtLines->CreateConstIterator();
			if (!(*It).IsEmpty()) {
				ccGettingCloser = *It;
				++It;
			}
			if (!(*It).IsEmpty()) {
				ccMovingAway = *It;
				++It;
			}
			if (!(*It).IsEmpty()) {
				ccFromTheLeft = *It;
				++It;
			}
			if (!(*It).IsEmpty()) {
				ccFromTheRight = *It;
				++It;
			}
			if (!(*It).IsEmpty()) {
				ccAhead = *It;
				++It;
			}
			if (!(*It).IsEmpty()) {
				ccBehind = *It;
				++It;
			}
			if (!(*It).IsEmpty()) {
				ccAbove = *It;
				++It;
			}
			if (!(*It).IsEmpty()) {
				ccBellow = *It;
				UE_LOG(LogTemp, Warning, TEXT("UMultisensoryAccessibilityAudioComponent: All cc descriptions successfully loaded"));
			}
	     } else {
	        UE_LOG(LogTemp, Warning, TEXT("UMultisensoryAccessibilityAudioComponent: Did not load text from file"));
	     }
	} else {
	   UE_LOG(LogTemp, Warning, TEXT("UMultisensoryAccessibilityAudioComponent: ERROR: Can not read the file because it was not found. Expected file location: %s"),*file);
	}
}
