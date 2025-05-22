/* 
	Multi-sensory Accessibility Plugin for UE5
 	Copyright 2025, Francisco Fortes

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at: http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and limitations under the License.
*/

#include "MultisensoryAccessibilityAudioComponent.h"
#include "Misc/AutomationTest.h"

#define LOCTEXT_NAMESPACE "FMultisensoryAccessibilityModule" 

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAudioTest, "MultisensoryAccessibility.AudioTests", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAudioTest::RunTest(const FString& Parameters)
{
    UMultisensoryAccessibilityAudioComponent* TestComponent = NewObject<UMultisensoryAccessibilityAudioComponent>();
    // Thresolds tests   
	int16 Threshold = TestComponent->kDistanceThreshold; 
    TestEqual(TEXT("Coord greater than threshold"), 
		TestComponent->relativePos(Threshold + 5), 
		1
	);
    TestEqual(TEXT("Coord less than -threshold"), 
		TestComponent->relativePos(-Threshold - 5), 
		-1
	);
    TestEqual(TEXT("Coord within threshold"), 
		TestComponent->relativePos(Threshold - 5), 
		0
	);
    TestEqual(TEXT("Coord exactly threshold"), 
		TestComponent->relativePos(Threshold), 
		0
	);
    TestEqual(TEXT("Coord exactly -threshold"), 
		TestComponent->relativePos(-Threshold), 
		0
	);

	// Delta tests
	TestComponent->previousDistance = 50;
    FVector PlayerLocation(0, 0, 0);
    FVector emitterLocation(260, 200, 100);   
    TestEqual(TEXT("emitter moves away"), 
		TestComponent->deltaPosChange(PlayerLocation, emitterLocation), 
		1
	);    
    emitterLocation = FVector(40, 0, 0);
    TestEqual(TEXT("emitter moves closer"), 
		TestComponent->deltaPosChange(PlayerLocation, emitterLocation), 
		-1
	);    
    emitterLocation = FVector(41, 0, 0);
    TestEqual(TEXT("No significant change in position"), 
		TestComponent->deltaPosChange(PlayerLocation, emitterLocation), 
		0
	);

    // Subtitle build text
    TestEqual(TEXT("Both texts empty"), 
		TestComponent->appendFormatted(FText::FromString(""), FText::FromString(""), FText::FromString(",")).ToString(), 
		FText::FromString("").ToString()
	);
    TestEqual(TEXT("Current text empty"), 
		TestComponent->appendFormatted(FText::FromString(""), FText::FromString("Hello"), FText::FromString(",")).ToString(), 
		FText::FromString("Hello").ToString()
	);    
    TestEqual(TEXT("New text empty"),  
		TestComponent->appendFormatted(FText::FromString("Hello"), FText::FromString(""), FText::FromString(",")).ToString(), 
		FText::FromString("Hello").ToString()
	);
    TestEqual(TEXT("Both texts with space separator"), 
		TestComponent->appendFormatted(FText::FromString("Hello"), FText::FromString("World"), FText::FromString("")).ToString(), 
		FText::FromString("Hello World").ToString()
	);
    TestEqual(TEXT("Both texts with dash separator"), 
		TestComponent->appendFormatted(FText::FromString("Hello"), FText::FromString("World"), FText::FromString("-")).ToString(), 
		FText::FromString("Hello- World").ToString()
	);

	// Location values text
	struct TestCase {
        FVector PosVector;
        FVector PlayerLocation;
        FVector ActorLocation;
        FString ExpectedText;
    };
	TestComponent->previousDistance = 550;
    TArray<TestCase> TestCases = {
        {{250, -220, 330}, {0, 0, 0}, {250, -220, 330}, "ahead, above from the left"},
        {{-350, 320, -330}, {0, 0, 0}, {-350, 320, -330}, "moving away behind, bellow from the right"},
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, "getting closer"},
        {{330, 330, 330}, {-100, -100, 100}, {-130, -0, 0}, "moving away ahead, above from the right"},
        {{-330, -330, -330}, {0, 200, 0}, {-0, -0, -0}, "behind, bellow from the left"}
    };
    for (const auto& TestCase : TestCases)
    {
        FText ResultText = TestComponent->getLocationText(TestCase.PosVector, TestCase.PlayerLocation, TestCase.ActorLocation);
        TestEqual(FString::Printf(TEXT("Location test for PosVector (%.0f, %.0f, %.0f)"), TestCase.PosVector.X, TestCase.PosVector.Y, TestCase.PosVector.Z), ResultText.ToString(), TestCase.ExpectedText);
    }
    
    return true;
}