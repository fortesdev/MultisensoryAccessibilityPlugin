/* 
	Multi-sensory Accessibility Plugin for UE5
 	Copyright 2025, Francisco Fortes

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at: http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and limitations under the License.
*/

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