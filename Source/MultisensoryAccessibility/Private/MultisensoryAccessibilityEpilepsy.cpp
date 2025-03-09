/* 
	Multi-sensory Accessibility Plugin for UE5
 	Copyright 2025, Francisco Fortes

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at: http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and limitations under the License.
*/

#include "MultisensoryAccessibilityEpilepsy.h"

// define a print message function to print to screen
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)  // display for 1.5 seconds
#define printFString(text, fstring, floatDisplayTime) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, float(floatDisplayTime), FColor::Magenta, FString::Printf(TEXT(text), fstring))  // display for x seconds

inline const uint32_t SmallestPowerOf2_GE_N(uint32_t N)
{
    N--;
    N |= N >> 1;
    N |= N >> 2;
    N |= N >> 4;
    N |= N >> 8;
    N |= N >> 16;
    N++;
    return N;
}

// Sets default values
AMultisensoryAccessibilityEpilepsy::AMultisensoryAccessibilityEpilepsy()
    : resolutionX(32)
    , resolutionY(32)
    , field_of_view(90.0f)
    , maxBlinksPerSecond(3)
    , screenFragmentToCheck(5)
    , maxColorDistance(250)
    , maxLuminanceDistance (75)
{
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.TickGroup = TG_PostUpdateWork;  // Perform tick after all updates, movement, physics is complete
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    if (cameraActor) 
    { // Not recommended and potentially buggy - generated camera component offers better results
        ourCamera = cameraActor->GetCameraComponent();
    } else 
    { // generated component, default and recommended way
        ourCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewportCamera"));
        ourCamera->SetupAttachment(RootComponent);
    }
    sceneCapture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneCapture"));   
    sceneCapture->SetupAttachment(ourCamera);
}

void AMultisensoryAccessibilityEpilepsy::BeginPlay()
{
    Super::BeginPlay();
    uint32_t higher = resolutionX > resolutionY ? resolutionX : resolutionY;
    internResolution = SmallestPowerOf2_GE_N(higher);
    // printFString("internResolution is: %d", internResolution, 5.f);
    ourCamera->FieldOfView = field_of_view;
    sceneCapture->FOVAngle = field_of_view;
    renderTarget = NewObject<UTextureRenderTarget2D>();
    renderTarget->InitCustomFormat(internResolution, internResolution, EPixelFormat::PF_B8G8R8A8, true);  
    renderTarget->UpdateResourceImmediate();
    sceneCapture->CaptureSource = SCS_FinalColorLDR;
    sceneCapture->TextureTarget = renderTarget;
    sceneCapture->bCaptureEveryFrame = true;
    sceneCapture->bAlwaysPersistRenderingState = true;
    startingMeasurementMs = FDateTime::UtcNow().GetMillisecond();
    startingMeasurementS = FDateTime::UtcNow().GetSecond();
    blinkingCountPerSec = 0;
    didBlink = false;
}

// Called every frame
void AMultisensoryAccessibilityEpilepsy::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    FillTexture(1.0f / DeltaTime);
}

void AMultisensoryAccessibilityEpilepsy::FillTexture(float fps)
{
    /*
    Explanation of this method:
         1. Each frame saves one buffer. Each bugger contains the colour of each pixel (default, 32*32=1024 pixels)
         2. We average between current frame and the previous, and that value is averaged with the next average. Then:
            a) If the difference is bigger than delta (thresold considered as "blinking") for one single pixel, and
            b) The number of pixels exceeds the constant N (the minimum percentage of screen to worry about), then
            c) The new averages are saved for a time T and, the blinking counter increases, and when a number of blinks is exceeded, a "danger" event is propagated.
            d) If no blink happens after double the expected interval, the values are cleaned and a "no danger" event is propagated.
    */
    int32 currentMs = FDateTime::UtcNow().GetMillisecond();
    int32 currentS = FDateTime::UtcNow().GetSecond();
    int32 adjustedCurrentMs = currentMs >= startingMeasurementMs ? currentMs : startingMeasurementMs + currentMs;
    int32 adjustedCurrentS = currentS >= startingMeasurementS ? currentS : startingMeasurementS + currentS;
    if ((adjustedCurrentS - startingMeasurementS) >= 2)
    {
        startingMeasurementS = currentS;
        UE_LOG(LogClass, Log, TEXT("Current fps: %f"), fps );
        if (blinkingCountPerSec/2 >= maxBlinksPerSecond) 
        { 
            UE_LOG(LogClass, Log, TEXT("EPILEPSY DANGER: %d blinks per second maxColorDistance %d"), blinkingCountPerSec/2, maxColorDistance );
            if (!didBlink) 
            {
                didBlink = true;
                // Here we send a screen block signal
                delegate.ExecuteIfBound(true);
            }
        } 
        else if (didBlink) 
        {
            didBlink = false; 
            UE_LOG(LogClass, Log, TEXT("EPILEPSY STATUS: %d blinks per second maxColorDistance %d"), blinkingCountPerSec/2, maxColorDistance );
            // Here we'll send an Unblock screen signal
            delegate.ExecuteIfBound(false);
        }
        blinkingCountPerSec = 0;
    }
    
    if ((adjustedCurrentMs - startingMeasurementMs) >= 50) { // Sligthly more than 1000ms / 20 (to measure until 20 flashes per second)
        // printFString("Current fps: %f", fps, 0.05f);
        // UE_LOG(LogClass, Log, TEXT("currentS: %d adjustedCurrentS: %d"), currentS, adjustedCurrentS );
        startingMeasurementMs = currentMs;
        framesPerSecond = fps;
        auto RenderTargetResource = renderTarget->GameThread_GetRenderTargetResource();
        if (RenderTargetResource) 
        {
           TArray<FColor> buffer8;
           RenderTargetResource->ReadPixels(buffer8);
           if (prevBuffer8.Num() == buffer8.Num()) 
           {
               int32 min=9999;
               int32 max=0;
               uint32 blinkPixelCount = 0;
               bool screenBlink = false;
               int32 luminance = 0;
               for (int i = 0; i < buffer8.Num(); i++) 
               {
                    int32 distance = ColourDistance(buffer8[i], prevBuffer8[i]);
                    luminance = LuminanceDistance(buffer8[i], prevBuffer8[i]);
                    if (min > luminance) { min = luminance; } 
                    if (max < luminance) { max = luminance; }
                    if (abs(distance) > maxColorDistance || luminance >= maxLuminanceDistance) { blinkPixelCount++; }
                }
                //UE_LOG(LogClass, Log, TEXT("Max Luminance: %d Min Luminance: %d blinkPixelCount: %d"), max, min, blinkPixelCount);
                if (blinkPixelCount > (internResolution*internResolution)/screenFragmentToCheck) { // At least a fitfh of the screen blinked
                    blinkingCountPerSec++;
                }
           }
           prevBuffer8 = buffer8;
        }   
    } 
}

// Two colors may be far apart (ie pure green vs pure red), and their blinking may be triggering, even with similar brightness. 
// This method is improved/complemented by LuminanceDistance method below
int32 AMultisensoryAccessibilityEpilepsy::ColourDistance(FColor color1, FColor color2)
{
    int32 rmean = (color1.R + color2.R) / 2;
    int32 r = color1.R - color2.R;
    int32 g = color1.G - color2.G;
    int32 b = color1.B - color2.B;
    return sqrt((((512+rmean)*r*r)>>8) + 4*g*g + (((767-rmean)*b*b)>>8));
}

// Luminance intensity value, to detect cases where the colour distance is not that far but the brightness change is  
int32 AMultisensoryAccessibilityEpilepsy::LuminanceDistance(FColor color1, FColor color2)
{
    // https://en.wikipedia.org/wiki/Relative_luminance
    // https://stackoverflow.com/questions/596216/formula-to-determine-perceived-brightness-of-rgb-color
    int32 lum1 = 0.2126*color1.R + 0.7152*color1.G + 0.0722*color1.B; 
    int32 lum2 = 0.2126*color2.R + 0.7152*color2.G + 0.0722*color2.B;
    return abs(lum1 - lum2);
}


void AMultisensoryAccessibilityEpilepsy:: CallbackEpilepsy(FEpilepsyDelegate callback, bool blinkDetected)
{ 
    //FEpilepsyDelegate delegate binding method into the blueprint 
    delegate.BindUFunction(callback.GetUObject(), callback.GetFunctionName());         
 }
