/* 
	Multi-sensory Accessibility Plugin for UE5
 	Copyright 2025, Francisco Fortes

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at: http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and limitations under the License.
*/

#include "MultisensoryAccessibilityColorBlindness.h"
#include "Misc/AutomationTest.h"

#define LOCTEXT_NAMESPACE "FMultisensoryAccessibilityModule" 

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FColorTest, "MultisensoryAccessibility.ColorTests", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FColorTest::RunTest(const FString& Parameters)
{
    // LUT construction of texturePath filename
	struct TestCaseLUT
    {
        EAffectedColorCone Cone;
        EColorBlindMode Mode;
        FString ExpectedPath;
    };

    TArray<TestCaseLUT> TestCasesLUT = {
        { EAffectedColorCone::Red, EColorBlindMode::Simulate, "/Script/Engine.Texture2D'/MultisensoryAccessibility/LUTs/protanope_simulate_lut.protanope_simulate_lut'" },
        { EAffectedColorCone::Red, EColorBlindMode::Correct, "/Script/Engine.Texture2D'/MultisensoryAccessibility/LUTs/protanope_correct_lut.protanope_correct_lut'" },
        { EAffectedColorCone::Green, EColorBlindMode::SimulateCorrected, "/Script/Engine.Texture2D'/MultisensoryAccessibility/LUTs/deuteranope_daltonise_lut.deuteranope_daltonise_lut'" },
        { EAffectedColorCone::Blue, EColorBlindMode::Simulate, "/Script/Engine.Texture2D'/MultisensoryAccessibility/LUTs/tritanope_simulate_lut.tritanope_simulate_lut'" },
        { EAffectedColorCone::Green, EColorBlindMode::Correct, "/Script/Engine.Texture2D'/MultisensoryAccessibility/LUTs/deuteranope_correct_lut.deuteranope_correct_lut'" },
        { EAffectedColorCone::None, EColorBlindMode::Simulate, "" } // None should return empty
    };

    for (const TestCaseLUT& Test : TestCasesLUT)
    {
        FString Result = UMultisensoryAccessibilityColorBlindness::GetLUTTexturePath(Test.Cone, Test.Mode);
        TestEqual(FString::Printf(TEXT("Testing Cone %d, Mode %d"), (int)Test.Cone, (int)Test.Mode), Result, Test.ExpectedPath);
    }

    // Interpolation for Shader mode

    struct TestCaseShader
    {
        float Low;
        float High;
        float Weight;
        float ExpectedResult;
    };

    TArray<TestCaseShader> TestCasesShaders = {
        { 0.0f, 10.0f, 0.0f, 0.0f },   // No interpolation (weight = 0)
        { 0.0f, 10.0f, 0.5f, 5.0f },   // Midpoint interpolation
        { -5.0f, 5.0f, 0.75f, 2.5f },  // 75% interpolation between negative and positive
        { 10.0f, 20.0f, 1.0f, 20.0f }  // Full interpolation (weight = 1)
    };

    for (const TestCaseShader& Test : TestCasesShaders)
    {
        float Result = UMultisensoryAccessibilityColorBlindness::interpolate(Test.Low, Test.High, Test.Weight);
        TestEqual(FString::Printf(TEXT("Interpolating between %f and %f with weight %f"), Test.Low, Test.High, Test.Weight), Result, Test.ExpectedResult);
    }

	return true;
}