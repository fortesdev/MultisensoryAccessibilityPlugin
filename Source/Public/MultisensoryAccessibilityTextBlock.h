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
//#include "UObject/Interface.h"
#include "Components/TextBlock.h"
#include "MultisensoryAccessibilityTextBlock.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSubtitleReceivedSignature, const FText&, SubtitleText);

UINTERFACE(MinimalAPI, NotBluePrintable, BlueprintType)
class UUOMultisensoryAccessibilityDSubtitleInterface : public UInterface
{
	GENERATED_BODY()
};

class IUOMultisensoryAccessibilityDSubtitleInterface 
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category="SubtitleHook")
	virtual void UpdateSubtitleText(const FText& SubtitleText) = 0;

	bool bAutoUpdateText = true;

private:

};


UCLASS()
class UMultisensoryAccessibilityTextBlock: public UTextBlock, public IUOMultisensoryAccessibilityDSubtitleInterface
{
	GENERATED_BODY()

public:
	UMultisensoryAccessibilityTextBlock(const FObjectInitializer& ObjectInitializer);
	virtual void UpdateSubtitleText(const FText& SubtitleText) override;
   	UPROPERTY(BluePrintAssignable, Category = "SubtitleHook")
		FSubtitleReceivedSignature OnSubtitleReceived;
private:
    FText originalTextValue = FText::GetEmpty();
	bool bOriginalTextSet = false;
};

