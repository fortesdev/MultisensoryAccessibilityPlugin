

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

