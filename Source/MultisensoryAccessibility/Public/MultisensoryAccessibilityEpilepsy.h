
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "Camera/CameraActor.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Engine/TextureRenderTarget2D.h"
#include "MultisensoryAccessibilityEpilepsy.generated.h"

// https://benui.ca/unreal/delegates-advanced/
DECLARE_DYNAMIC_DELEGATE_OneParam(FEpilepsyDelegate, bool, blinkDetected);
UCLASS(BlueprintType)
class AMultisensoryAccessibilityEpilepsy : public AActor
{
    GENERATED_BODY()

public:
    // Necesita empezar con A al ser un Actor. No tener ese prefijo hace q no compile y podria romper el proyecto.
    AMultisensoryAccessibilityEpilepsy();

    UFUNCTION(BlueprintCallable) 
    void CallbackEpilepsy(FEpilepsyDelegate callback, bool blinkDetected); 

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Create the image in texture
    void FillTexture(float fps);

    int32 ColourDistance(FColor color1, FColor color2);

    int32 LuminanceDistance(FColor color1, FColor color2);

    // Textures need to be power of 2
    uint32_t internResolution;

    UTextureRenderTarget2D* renderTarget;
    
    class UCameraComponent* ourCamera;
    
    int32 startingMeasurementMs;

    int32 startingMeasurementS;

    uint32 blinkingCountPerSec;

    float framesPerSecond;

    bool didBlink;

    TArray<FColor> prevBuffer8; // array exists but empty on this definition

    FEpilepsyDelegate delegate; 

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, Category = "Output Information", meta = (ClampMin = "32", ClampMax = "4096", UIMin = "32", UIMax = "4096"))
        uint32 resolutionX;

    UPROPERTY(EditAnywhere, Category = "Output Information", meta = (ClampMin = "32", ClampMax = "4096", UIMin = "32", UIMax = "4096"))
        uint32 resolutionY;

    UPROPERTY(EditAnywhere, Category = "Output Information", meta = (ClampMin = "20.0", ClampMax = "179.9", UIMin = "20.0", UIMax = "179.9"))
        float field_of_view;

    UPROPERTY(EditAnywhere, Category = "Output Information")
        class USceneCaptureComponent2D* sceneCapture;

    UPROPERTY(EditAnywhere, Category = "Input Information")
        class ACameraActor* cameraActor;

    UPROPERTY(EditAnywhere, Category = "Output Information", meta = (ClampMin = "0", ClampMax = "60", UIMin = "0", UIMax = "60"))
        uint32 maxBlinksPerSecond;

    UPROPERTY(EditAnywhere, Category = "Output Information", meta = (ClampMin = "1", ClampMax = "100", UIMin = "1", UIMax = "100"))
        uint32 screenFragmentToCheck; // 1 is the whole screen, 5 is a fifth (default), meaning, if a blink happens in 1/5 of all pixels, it triggers the detection

    UPROPERTY(EditAnywhere, Category = "Output Information", meta = (ClampMin = "0", ClampMax = "400", UIMin = "0", UIMax = "400"))
        int32 maxColorDistance;

    UPROPERTY(EditAnywhere, Category = "Output Information", meta = (ClampMin = "0", ClampMax = "100", UIMin = "0", UIMax = "100"))
        int32 maxLuminanceDistance;
};