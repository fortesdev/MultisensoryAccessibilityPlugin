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
    if (cameraActor) { // Usamos la camara proporcionada. Esto debe probarse en el 3rd person mode, ya que se habra incluido en el Player actor
        ourCamera = cameraActor->GetCameraComponent();
    } else { // Creamos el nuestro propio
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
    renderTarget->InitCustomFormat(internResolution, internResolution, EPixelFormat::PF_B8G8R8A8, true);  // some testing with EPixelFormat::PF_FloatRGBA, true=force Linear Gamma
    renderTarget->UpdateResourceImmediate();

    sceneCapture->CaptureSource = SCS_FinalColorLDR;     // SCS_FinalColorLDR allows for post processing on the image.  default = SCS_SceneColorHDR
    sceneCapture->TextureTarget = renderTarget;
    sceneCapture->bCaptureEveryFrame = true;
    sceneCapture->bAlwaysPersistRenderingState = true;  // This allows velocities for Motion Blur and Temporal AA to be computed.
    //tickCount = 0;
    startingMeasurementMs = FDateTime::UtcNow().GetMillisecond();
    startingMeasurementS = FDateTime::UtcNow().GetSecond();
    blinkingCountPerSec = 0;
    didBlink = false;
}

// Called every frame
void AMultisensoryAccessibilityEpilepsy::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    //tickCount++;
    FillTexture(1.0f / DeltaTime);
}

void AMultisensoryAccessibilityEpilepsy::FillTexture(float fps)
{
    int32 currentMs = FDateTime::UtcNow().GetMillisecond();
    int32 currentS = FDateTime::UtcNow().GetSecond();
    int32 adjustedCurrentMs = currentMs >= startingMeasurementMs ? currentMs : startingMeasurementMs + currentMs;
    int32 adjustedCurrentS = currentS >= startingMeasurementS ? currentS : startingMeasurementS + currentS;
    if ((adjustedCurrentS - startingMeasurementS) >= 2)
    {
        startingMeasurementS = currentS;
        UE_LOG(LogClass, Log, TEXT("Current fps: %f"), fps );
        if (blinkingCountPerSec/2 >= maxBlinksPerSecond) { 
            UE_LOG(LogClass, Log, TEXT("EPILEPSY DANGER: %d blinks per second maxColorDistance %d"), blinkingCountPerSec/2, maxColorDistance );
            if (!didBlink) {
                didBlink = true;
                //Here we send a screen block signal
                delegate.ExecuteIfBound(true);
            }
        } else if (didBlink) {
            didBlink = false; 
            UE_LOG(LogClass, Log, TEXT("EPILEPSY STATUS: %d blinks per second maxColorDistance %d"), blinkingCountPerSec/2, maxColorDistance );
            // Here we'll send a screen UNblock signal
            delegate.ExecuteIfBound(false);
        }
        blinkingCountPerSec = 0;
    }
    
    if ((adjustedCurrentMs - startingMeasurementMs) >= 50) { // Sligthly more than 1000ms / 20 (to measure until 20 flashes per second)
    //    printFString("Current fps: %f", fps, 0.05f);
       // UE_LOG(LogClass, Log, TEXT("currentS: %d adjustedCurrentS: %d"), currentS, adjustedCurrentS );
        startingMeasurementMs = currentMs;
        framesPerSecond = fps;
        auto RenderTargetResource = renderTarget->GameThread_GetRenderTargetResource();
        if (RenderTargetResource) {
           TArray<FColor> buffer8;
           RenderTargetResource->ReadPixels(buffer8);
           if (prevBuffer8.Num() == buffer8.Num()) {
               int32 min=9999;
               int32 max=0;
               uint32 blinkPixelCount = 0;
               bool screenBlink = false;
               int32 luminance = 0;
               for (int i = 0; i < buffer8.Num(); i++) {
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
    /*
         Por cada frame se guarda 1 buffer. Cada buffer contiene el color de 1024 pixels
         Se hace siempre la media entre frame-2 y frame-1, para compararse con frame.
            a) Si hay una diferencia mayor q delta (thresold considerado "parpadeo" - a evaluar que color y contraste lo provoca) para un solo pixel, y
            b) El numero de pixel excede N (considerado mas de un tercio de la pantalla), then
            c) Los frames frame-2 y frame-1 se sobreescriben con frame, y se guarda un valor tiempo T
        Si se suceden 2 parpadeos entre el rango considerado como peligroso, se entra en modo "Peligro" hasta q pase el doble de tiempo sin suceder intervalos
        Si el rango excede, borramos el tiempo
    */
   
    } 
    /*
        Para cada unidad de medida, comparar la distancia entre current pixels y unos previamente guardados (importante considerar el rojo).
        Si mas de 1/x se percibe como parpadeo, guardarlo como tal. (crear variable)
        Si se producen "y" o mas parpadeos por segundo, ese segundo es peligroso. Cada 2 segundos marcados provocan que el tercero sea bloqueado. (crear variable)
    */


}

// Two colors may be far apart (ie pure green vs pure red), and their blinking may be triggering
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
    //https://en.wikipedia.org/wiki/Relative_luminance
    //https://stackoverflow.com/questions/596216/formula-to-determine-perceived-brightness-of-rgb-color
    int32 lum1 = 0.2126*color1.R + 0.7152*color1.G + 0.0722*color1.B; 
    int32 lum2 = 0.2126*color2.R + 0.7152*color2.G + 0.0722*color2.B;
    return abs(lum1 - lum2);
}


void AMultisensoryAccessibilityEpilepsy:: CallbackEpilepsy(FEpilepsyDelegate callback, bool blinkDetected)
{ 
    //FEpilepsyDelegate delegate; 
    delegate.BindUFunction(callback.GetUObject(), callback.GetFunctionName());         
    
 }
