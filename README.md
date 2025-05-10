# Multi-sensory Accessibility Plugin for Unreal Engine 5

### Aid for hearing loss, low vision, color blindness and epilepsy.

Video demo:

[![Click to see a video demo](https://img.youtube.com/vi/Re8e1cGwqGI/0.jpg)](https://www.youtube.com/watch?v=Re8e1cGwqGI)

The goal of this plugin is simple: making accessibility in Unreal projects as cheap and easy as possible. Because everyone wants a wider audience and helping others to enjoy our creations. For that purpose, I have prepared a set of built-in methods and classes to cover the following access needs:

1. **Hearing aid:**
   - The plugin offers a system for dynamic subtitles, which provides real-time spatial information relative to the player: a 3D sound emitter will concatenate its defined subtitle with "getting closer/moving away", "from the right/left", "ahead/behind" and "above/bellow".
   - While not included as part of the plugin (given the external infrastructure needed), we suggest (in the last section "Future Machine Learning improvements") a method for having Audio description using AI: from a static "Gun shot" string, the player may get a more descriptive "Gun shut from the left, behind you, above".
2. **Low vision:**
   - To cover a wide range of neural or eye disorders, the plugin offers two modes: Enhanced Contrast mode (a variant of cel-shading where unnecessary details are removed, while contours are highlighted), and Monochrome  mode, where only the outlines are offered. All parameters such as highlight colors, depth, etc. can be adjusted in real time for a more refined aid.
   - A "low visibility simulation" mode is offered, for testing the contrast settings while debugging.
3. **Color blindness:**
   - While a color blindness help support exists in UE, this plugin enhances its customisation in the following aspects:
   - Color blindness corrections are applied in a Post-processing volume, instead of the general rendering pipeline. As result, the correction can be applied in the map and not the UI, in specific areas of the level instead of everywhere, and be combined with other shaders, for a more refined aid.
   - Opposite to the built-in help in UE, with all parameters hardcoded (including the severity levels), the plugin re-work the color transformations and allows floating point adjustments for all its inputs.
   - Two correction modes are offered instead of one: the common shader solution (more physiologically precise), but also a variant that uses Look-up tables (LUTs), for a more flexible solution (for example, reducing the information loss if problematic color patterns are known).
4. **Epilepsy:**
   - The plugin offers an attempt at detecting dangerous blinking, so players affected by epilepsy can be protected. Note that there are inherent risks, and this capability must be used responsibly: as there can be false positives, also false negatives may arise. For instance: different people may be affected by different blinking intervals, and the blinking source may be intermittently hidden by actors during gameplay, affecting the plugin's output.


# Plugin setup steps

1. Close the Unreal Editor.
2. Create a folder "Plugins" in the root of your project, if you don't have one already.
3. Copy the Multi-sensory Accessibility plugin folder into "Plugins".
4. Re-open your project in the Unreal Editor.
5. If it asks to rebuild the plugin (ie. because "it was build by a different version"), click yes. Depending on your hardware, and if you work in a C++ project already or not, building the plugin may need from a few seconds to minutes.
6. Go to Editor/Plugins, and check that Multi-sensory Accessibility Plugin is enabled. 
    
# Dynamic subtitles setup

1. Subtitles are offered in Unreal with UI widgets. Usually, a text block will be used by the built-in subtitles system. And the plugin uses a similar approach: acting as intermediary between the audio system and the subtitles. That way, you can reuse your existing logic just by changing the classes involved. For instance, instead of the default text block, you need to use in your widget the plugin's *MultiSensoryAccessibilityTextBlock* class. As example, there is a *SubtitleWidgetBP* offered within the plugin's Content/Widgets folder, ready to use.
2. Subtitle texts are defined as usual, no changes here: they must appear in the settings of your imported audio assets, as in the screenshot below. The subtitles you define will be the "constant strings" that will be completed in run time, by the plugin, with dynamic descriptions.
   
![addSubtitle](https://github.com/user-attachments/assets/4a35b672-4b30-4631-9b72-190abd21b622)

4. Your audio asset, obviously, needs to be emitted by someone within the map, usually an actor. But instead of adding a default audio component to your actor, you need to add the plugin's MultiSensoryAccessibilityAudio component. Once this is included (see the capture underneath), you need to convert your actor to a reusable blueprint class (if it is not already), with the button for such purpose.
   
![Screenshot 2025-03-09 at 17 06 03](https://github.com/user-attachments/assets/7cf65aec-a16b-477c-9fa1-b454a6ea4b18)

6. Once converted, please open for editing the blueprint class of your actor, and initialise the *MultiSensoryAccessibilityAudio* variable so you have easy access to it (you'll need it).
7. Then, decide when and how frequently the dynamic subtitles need to be updated (with the provided blueprint method "Update location based subtitles", from the MultiSensoryAccessibilityAudio component). For simplicity, you can update it in every Tick, but keep in mind, too quick updates may be confusing for the player, and can produce instabilities in the engine's subtitles system. We recommend updating once every quarter of half a second.

![Screenshot 2025-03-09 at 17 09 23](https://github.com/user-attachments/assets/05947621-3966-4efe-957e-cd5612eba6dc)

8. Now, you decide when to create and add (or remove from the viewport) your UI widget for the subtitles. For example, you could add to viewport in your map's *EventBeginPlay*.
9. The values for the dynamic descriptions (above/below/ahead/from the back, etc.) can also be customised and localised. This is achieved by defining the source file for the strings in the editor's variable *ccLocalisedDescriptions*, or the method *changeSubtitlesFile*, of your MultiSensoryAccessibilityAudio component. Important: the plugin needs to read text files, that will not be included in the shipping packaging by default (even if they are in your Content folder) unless you define them in your packaging options. We recommend to store your text files in a dedicated folder, include this folder in the packaging copy options, and write the relative path of the folder when setting it in the component (ie "myFolderName/subtitleEN.srt").
10. The *interpretation* of the relative positions between the sound emitter and the player can also be adapted to the user's perspective. For example, in first person, the direction the player sees matches exactly, and at all times, the FirstPlayerController's pawn view. But that's not the case in third person, where your character mesh can be looking directly at the camera (at the actual player), so the pawn's back is actually the camera's front, reversing left and right. But you can decide what perspective will be taken into consideration and beter adapts to your player with the component's boolean *isObservedInFirstPerson*. By default, it will be false, so the player's pawn view is considered.
11. The next step is setting sounds to your actor, and play or stop them. Dynamic subtitles will be display automatically while the audio asset is being emitted.

![Screenshot 2025-03-09 at 17 09 58](https://github.com/user-attachments/assets/70204307-8a01-4573-be19-e372f5761afa)

# Low vision aid setup

1. Visual effects in this plugin will be applied using post processing volumes and materials provided. But instead of using regular volumes, you will need to include in your map the plugin's *MultiSensoryAccessibilityPPVolume* class. You can add as many instances of this volumes as you want, and decide if they will apply to all map, or just its interior volume, by enabling (or not) its variable "Infinite Extend (unbound)".
   
![Screenshot 2025-03-09 at 17 12 45](https://github.com/user-attachments/assets/f07fe786-953c-4ab9-8d19-fbb68b4ff0d2)

2. All low vision changes are applied through a common blueprint method, called "Increase of color, contrast and vision within a volume". This method is injected with the following required parameters:
   1. An instance of *MultiSensoryAccessibilityPPVolume*, that we created previously.
   2. An instance to a MSMaterialParameter. This is a set of constant definitions used by the shaders. We provide one ready to use in the plugin's Content folder, but you can edit it and/or create your own. Some example of the constants are color thresolds, outline growth rate, and more. Keep in mind this file is shared with Color blindness aid, described later.
   3. A value for "color mode". It can be either *Normal* (aid disabled), *High contrast* (with unnecessary details and colors removed), and *Monochrome*.
   4. An outline color. We recommend light outline color in dark objects or over dark backgrounds, and viceversa. Remember you can change all this parameters in real time if you need so.
   5. An outline *Strenght* value. This will determine how thick the outlines are, customisable in real time as well.
   6. A bool for simulating low vision while debugging, for testing your implementation.
      
 ![Screenshot 2025-03-09 at 17 13 19](https://github.com/user-attachments/assets/a25d3937-ca1d-446a-8fe1-934694d0c60d)


# Color blindness aid setup

1. Similar to the low vision aid, this feature uses one (or more) instances of the *MultiSensoryAccessibilityPPVolume* class, to add to your map. Remember to decide if you want the visual aids to be applied only within this Post-processing volume, or to the whole map, by keeping disabled, or enabling, *Infinite Extend (unbound)* in the volume settings.
2. All color blindness aid changes are applied through a common blueprint method provided, called *Simulation and correction of different color blindness (Dichromacy)*. This method is injected with the following required parameters:
   1.  An instance of *MultiSensoryAccessibilityPPVolume*, that we created previously.
   2. The affected eye cone type. The possible values are *none* (no deficiency), *red*, *green* and *blue*.
   3. An instance to a *MSMaterialParameter*. This is a set of constant definitions used by the shaders. We provide one ready to use in the plugin's Content folder. We do not recomment altering it for the color blindness. Keep also in mind this file is shared with Color blindness aid.
   4. The color technique used for the aid. One is *Shaders*, very precise, but strict and lacking contrast. The second is using *LUTs* (Look-up tables), that allows a more refined and artistic definition, but bad for HDR. We recommend using shaders unless you create your own LUT definitions based on your map color patterns.
   5. The mode of aid. You can *Simulate* (to see how a color blind person see), *Simulate Corrected* (to see the correction as a color blindness person), and *Correct*, which should be the mode applied in production with the aid enabled.
   6. The *Strenght* of the applied color changes (bigger the more severily affected a color cone is)
      
![Screenshot 2025-03-09 at 17 14 00](https://github.com/user-attachments/assets/0c174c80-4503-40ba-b01f-a038bc5f677e)

# Epilepsy aid setup

1. This aid skips the use of post-processing volumes and instead use a new class, called *MultiSensoryAccessibilityEpilepsy*, based on SceneCapture. So start by adding an instance of this new class into your map, preferably pointing to a critical area where the blinking is expected (you'll see a preview of its field of view). You can potentially also include this component in your player, by making sure (through code), that the Player's camera is feeding the Scene Capture of the component (simply adding it to your Player blueprint will not work, as it needs the correct directional coordinates). But we do not recommend this - more info at the end of this section.
2. Before using the *MultiSensoryAccessibilityEpilepsy*, take some time to check the available parameters this component provides in the editor:
   1. The resolution of the capture used for analysis. The higher, the more precise, but also more expensive hardware-wise (screen captures are analyzed between each frame)
   2. The field of view of the capture (ideally, equal to your player's camera).
   3. The max amount of blinks per second allowed. While under 5 is considered safe for most people, a conservative 3 is recommended.
   4. Screen fragment to check. This is the portion of the screen that must change in order for a blink to be considered dangerous. Default value is 5, which means, a blink in a fifth of the screen will trigger the recognition, while value 1 is the whole screen. Smaller the better protection, but the easier for false negatives to happen. This is the harder value to adjust as it depends on your gameplay.
      
 ![Screenshot 2025-03-09 at 17 14 47](https://github.com/user-attachments/assets/1b808459-2a8c-4500-87e6-0a4313a64e52)

3. Once you have added an instance of the epilepsy component and decided your values above, you can use the delegate method *Callback Epilepsy* to know when a blink is happening in run time (or the blinking has stopped). You are free to inform the user, or preferably, to block the dangerous view from the screen, when this happens.

 ![Screenshot 2025-03-09 at 17 14 22](https://github.com/user-attachments/assets/75a7d1ec-b43d-4862-b8c2-595cf953157a)

4. **Important**: please ensure a deep testing before including this Epilepsy aid, and warning the user about its existence. While false positives cause no harm, false negatives may happen for example due to actors, or even a third person player's mesh, intermittently blocking the light source of the blinking. This is one of the reasons the scene capture component is originally meant to be used statically in the map: being part of the player, linked to its moving camera, can increase errors, for example in fast pacing games. It is better to aim to "potentially hazardous" areas for as long as possible so the pixel calculations are not corrupted by movement. 

# Future Machine Learning improvements

Some other solutions were studied (while preparing this plugin) that are not included, as they required extra infrastructure (and this plugin is meant to be standalone and offline). These solutions are:

1. **Automatic Audio Descriptions**:
Google offers a decent [AI Audio Classifier](https://ai.google.dev/edge/mediapipe/solutions/audio/audio_classifier). You can host a web service that loads this model, access the web service in an Unreal's web widget, present it in your game UI, and send audio files or an audio stream to it. Your web service can then return a webpage with the classifications as a list of probabilities, to be listed in the user interface. This is feasible as of now, as seen in the video example at the beginning of the page, but there are a few (solvable) problems you need to keep in mind:
   1. Google's classification model has a tendency to filter background noise. This may be a problem for atmospheric and quiet games/situations, as important low volume sounds may be completely ignored. A new model would have to be trained for such specific situations.
   2. The AI model is also very indecisive, changing its mind in fractions of a second, which can make tricky to offer it in a stable UI, readable to the player. This can be perhaps even harder in a model that does not filter background noises.
   3. If you decide to not send static audios, but instead the mix of the audio from the game, you'll find out the only way to allow this through web in Unreal is using the microphone. But Unreal's default web component doesn't offer CEF (Chromium Experiment Features), so the microphone permissions cannot be changed. Fortunately, there are (paid) Unreal web plugins out there that offer this capability.

2. **Fast Neural Style Transfer**:

There is an official Neural Renderer plugin in UE5 that allows using ONNX models in post processing materials. For example those offered [here](https://github.com/onnx/models/tree/main/validated/vision/style_transfer/fast_neural_style). While giving a glimpse of future capabilities, this is currently an experimental feature that cannot be deployed in production (the packaging of your project will fail if you attempt to do so). Also, you'll have to train your model using an old version of PyTorch, then convert it to ONNX, with potential incompatibility issues. While interesting, it is not a recommended alternative to the shaders provided by the plugin, as neural models for rendering provide worse visual quality and efficiency.

## Feedback form

Do you wish to provide comments on the plugin? Please fill the following form to help the project: 
https://forms.gle/Rttr8U9UdCZRjzYZ8
