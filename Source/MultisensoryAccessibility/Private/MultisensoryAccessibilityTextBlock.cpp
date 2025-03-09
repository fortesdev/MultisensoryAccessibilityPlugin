// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultisensoryAccessibilityTextBlock.h"
#include "SubtitleManager.h"

#define LOCTEXT_NAMESPACE "FMultisensoryAccessibilityModule" 

UMultisensoryAccessibilityTextBlock::UMultisensoryAccessibilityTextBlock(const FObjectInitializer& ObjectInitializer)
{
	if (FSubtitleManager* subtitleManager = FSubtitleManager::GetSubtitleManager())
	{
		subtitleManager->OnSetSubtitleText().AddUFunction(this, FName("UpdateSubtitleText"));
	}
}

void UMultisensoryAccessibilityTextBlock::UpdateSubtitleText(const FText& SubtitleText)
{
	FString SubtitleTextString = SubtitleText.ToString();
	FString originalTextValueString = originalTextValue.ToString();
	
	if (SubtitleText.ToString().Compare(originalTextValue.ToString()) == 0) { // This includes the case where undefined
		return; // Nothing set or played yet, or received equal to original. We skip subtitle updates
	}

	if (!bOriginalTextSet) 
	{	
		bOriginalTextSet = true;
		originalTextValue = SubtitleText;
	}
	
	FText finalSubtitle = SubtitleText.ToString().Len() == 0 ? FText::GetEmpty() :
						 FText::Format(LOCTEXT("Subtitle", "{0} {1}"), originalTextValue, SubtitleText);

	if(bAutoUpdateText)
	{
		SetText(finalSubtitle);
	} else {
		if (OnSubtitleReceived.IsBound())
		{
			OnSubtitleReceived.Broadcast(finalSubtitle);
		}
	}
}