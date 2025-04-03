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
#include "Misc/AutomationTest.h"

#define LOCTEXT_NAMESPACE "FMultisensoryAccessibilityModule" 

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FEpilepsyTest, "MultisensoryAccessibility.EpilepsyTests", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FEpilepsyTest::RunTest(const FString& Parameters)
{
    struct TestCaseColourDistance
    {
        FColor Color1;
        FColor Color2;
        int32 ExpectedDistance;
    };

    TArray<TestCaseColourDistance> ColourTestCases = {
        { FColor(0, 0, 0), FColor(255, 255, 255), 764 },  // Black to White
        { FColor(255, 0, 0), FColor(0, 255, 0), 649 },    // Red to Green
        { FColor(0, 0, 255), FColor(255, 255, 0), 764 },  // Blue to Yellow
        { FColor(100, 100, 100), FColor(120, 120, 120), 59 }, // Close shades of grey
        { FColor(255, 0, 0), FColor(255, 255, 255), 624 } // Red to White
    };

    for (const TestCaseColourDistance& Test : ColourTestCases)
    {
        int32 Result = AMultisensoryAccessibilityEpilepsy::ColourDistance(Test.Color1, Test.Color2);
        TestEqual(FString::Printf(TEXT("Colour distance between (%d, %d, %d) and (%d, %d, %d)"),
            Test.Color1.R, Test.Color1.G, Test.Color1.B, Test.Color2.R, Test.Color2.G, Test.Color2.B),
            Result, Test.ExpectedDistance);
    }

    struct TestCaseLuminance
    {
        FColor Color1;
        FColor Color2;
        int32 ExpectedLuminanceDistance;
    };

    TArray<TestCaseLuminance> LuminanceTestCases = {
        { FColor(0, 0, 0), FColor(255, 255, 255), 254 }, // Black to White
        { FColor(50, 50, 50), FColor(200, 200, 200), 150 }, // Dark grey to light grey
        { FColor(255, 0, 0), FColor(0, 255, 0), 128 },  // Red to Green (similar luminance)
        { FColor(100, 100, 100), FColor(120, 120, 120), 20 }, // Slightly different greys
        { FColor(255, 255, 255), FColor(255, 200, 200), 43 } // White to slightly tinted white
    };

    for (const TestCaseLuminance& Test : LuminanceTestCases)
    {
        int32 Result = AMultisensoryAccessibilityEpilepsy::LuminanceDistance(Test.Color1, Test.Color2);
        TestEqual(FString::Printf(TEXT("Luminance distance between (%d, %d, %d) and (%d, %d, %d)"),
            Test.Color1.R, Test.Color1.G, Test.Color1.B, Test.Color2.R, Test.Color2.G, Test.Color2.B),
            Result, Test.ExpectedLuminanceDistance);
    }

    return true;
}