# Multi Sensory Accessibility Plugin for Unreal Engine 5

### Aid for hearing loss, low vision, color blindness and epilepsy.

Video demo:

[![Click to see a video demo](https://img.youtube.com/vi/BThkBb_bR0w/0.jpg)](https://www.youtube.com/watch?v=BThkBb_bR0w)

The goal of this plugin is to offer aid for deficiencies and needs currently not existing in Unreal, so developers can help as much players as possible without investing money, in just a few minutes. This includes:

1. Hearing aid
   - The plugin offers a system for dynamic subtitles, which provides real time spatial information relative to the player: a 3D sound emitter will concatenate its defined subtitle with "getting closer/moving away", "from the right/left", "ahead/behind" and "above/bellow".
   - While not included as part of the plugin (given the external infrastructure needed), we suggest a method for having Audio description using AI, etc. From a static "Gun shot" string, a player will get a more descriptive "Gun shut from the left, above, behind".
2. Low  vision
   - To cover a wide range of neural or ocular deficiencies, the plugin offers two modes: Enhanced Contrast mode (a variant of cel-shading where unnecessary details are removed, while countours are highlighted), and High Contrast mode, where only the countour of the monochrome silhouette is offered. All parameters such as highlight colors, depth, etc. can be adjusted in real time for a more refined aid.
   - A "low visibility simulation" mode is offered, for testing the contrast settings while debugging.
3. Color blidness
   - While a color blidness help support exists in UE, this plugins enhances its customisastion in the following aspects:
   - Color blidness corrections are applied in a Post-processing volume, instead as a general plugin. As result, the correction can be applied differently in specific areas of the level, and be combined with other shaders, for a more refined aid.
   - Opposite to the built-in help in UE, which offers 10 leves of severity only, the plugin allows a float value and more customisation options.
   - Two correction modes are offered: the common shader solution (more physiological precise), and also a variant that uses Look-up tables (LUT), for a more flexible solutions (for example, reducing the loss of information if the problematic color patterns are known).
4. Epilepsy
   - The plugin offers an attempt at detecting dangerous blinking, so players affected by epilepsy can be protected. Note that there are inherent risks and this capability must be used responsibly: as there can be false positives, also false negatives may arise. For instance: different people may be affected by different blinking intervals, and the blinking source may be intermittently hidden by actors during gameplay, affecting calculations. Feel free experimenting the the customisation if the default values do not fit your game.


# Plugin setup

1. Close the Unreal Editor.
2. Create a folder "Plugins" in the root of your project.
3. Copy the Multi-sensory Accessibility plugin folder into "Plugins".
4. Re-open your project in the Unreal Editor.
5. If it asks to rebuild a plugin (ie because "it was build by a different version"), click yes. Depending on your hardware, and if you work in a C++ project already or not, building the plugin may need from a few seconds to minutes.
6. Go to Editor/Plugins,  and check that Multi-sensory Accessibility plugin is activated. 
    
# Dynamic subtitles setup

1. You need an UI widget that will display the subtitles, offered through a component provided by the plugin, called MultiSensoryAccessibilityTextBlock. As example, check the SubtitleWidgetBP offered within the plugin's Content/Widgets folder.
2. Once you have an audio asset imported in your editor, go to its settings and define a subtitle(s) text. This is the constant string that will be completed with dynamic description in real time. The values for the dynamic descriptions (above/below/ahead/from the back, etc.) can be customised and localised by defining the source file for the strings in the variable "ccLocalisedDescriptions" in this component (the file you define needs to exist in your project's Content folder).
![addSubtitle](https://github.com/user-attachments/assets/4a35b672-4b30-4631-9b72-190abd21b622)
3. Now you need to have, in your Unreal map, an actor that will be the 3D audio emitter. 
4. Add to your actor a MultiSensoryAccessibilityAudio component, and convert it to reusable blueprint class with the button for such effect.
![Screenshot 2025-03-09 at 17 06 03](https://github.com/user-attachments/assets/7cf65aec-a16b-477c-9fa1-b454a6ea4b18)
5. Once the blueprint class for the actor is open for editing, assign your MultiSensoryAccessibilityAudio componen variable so you have easy access to it.
6. Decide when and how frequently the dynamic subtitles need to be updated (with the provided blueprint method "Update location based subtitles"). For simplicity, you could update it in every Tick, but keep in mind, too quick updates may be confusing for the player, so perhaps once even half a second or more is better (it depends on how fast your actors will move).
![Screenshot 2025-03-09 at 17 09 23](https://github.com/user-attachments/assets/05947621-3966-4efe-957e-cd5612eba6dc)
7. Now, you decide when to create and add or remove (in the viewport) your UI widget for the subtitles. For example, in your map EventBeginPlay.
![Screenshot 2025-03-09 at 17 09 58](https://github.com/user-attachments/assets/70204307-8a01-4573-be19-e372f5761afa)
8. The next step is set sounds to your actor and play or stop the audio asset. Dynamic subtitles will be display automatically.

# Low vision aid setup

1. Start by adding one (or more) MultiSensoryAccessibilityPPVolume. Decide if you want the visual aids to be applied only within this Post-processing volume, or to the whole map, by keeping disabled, or enabling "Infinite Extend (unbound)" in the volume settings.
2. All low vision changes are applied through a common blueprint method provided, called "Increase of color, contrast and vision within a volume". This volume is injected with the folloring required parameters:
   a. An instance of MultiSensoryAccessibilityPPVolume, that we created previously.
   b. An instance to a MSMaterialParameter. This is a set of constant definitions used by the shaders. We provide one ready to use in the plugin's Content folder, but you can edit it and/or create your own. Some example of the constants are color thresolds, outline growth rate, and more. Keep in mind this file is shared with Color blindness aid.
   c. A value for "color mode". It can be either "Normal" (aid disabled), "High contrast" (with unnecessary details and colors removed), and "Monochrome".
   d. An outline color. We recommend light outline color in dark objects or over dark backgrounds, and viceversa. Remember you can change all this parameters in real time.
   e. An outline "Strenght" value. This will determine how thick the outlines are, customisable in real time.
   f. A bool for simulating low vision while debugging, for testing your implementation.

# Color blindness aid setup

1. Start by adding one (or more) MultiSensoryAccessibilityPPVolume, if you didn't already. Decide if you want the visual aids to be applied only within this Post-processing volume, or to the whole map, by keeping disabled, or enabling "Infinite Extend (unbound)" in the volume settings.
2. All color blidness aid changes are applied through a common blueprint method provided, called "Simulation and correction of different color blindness (Dichromacy)". This volume is injected with the folloring required parameters:
   a.  An instance of MultiSensoryAccessibilityPPVolume, that we created previously.
   b. The affected eye cone type. The possible values are none (no aid), red, green and blue deficiencies.
   c. An instance to a MSMaterialParameter. This is a set of constant definitions used by the shaders. We provide one ready to use in the plugin's Content folder. We do not recomment altering it for the color blidness case, as it is edited by the plugin in real time. Keep also in mind this file is shared with Color blindness aid.
   d. The color technique used for the aid. One is Shaders, very biologically precise, but strict and lacking contrast. The second is using LUTs (Look-up tables), that allows a more refined and artistic definition. We recommend using shaders, unless you use your own LUT definitions.
   e. The mode of aid. You can Simulate (to see how a color blind person see), Simulate Corrected (to see the correction as a color blidness person), and Correct, which should be the mode applied in production with the aid enabled.
   f. The strenght or of the aid (bigger the more affected a color cone is)

# Epilepsy aid setup

1.  Start by adding a MultiSensoryAccessibilityEpilepsy instance to your map. This component includes a scene capture that will try to detect the blinking. You can potentially also include it in your player, by making sure (through code), that the Player's camera is feeding the Scene Capture of the component (simply adding it to your Player blueprint will work, as it needs the correct coordinates).
2.  There are a range of parameters you can customise in your Epilepsy aid component:
   a. The resolution of the capture used for analysis. The higher the more precise, but also more expensive (captures are analyses between each frame)
   b. The field of view of the capture (ideally equal to your game's settings).
   c. The max amount of blinks per second. While under 5 is considered safe for most people, a conservative 3 is recommended.
   d. Screen fragment to check. This is the portion of the screen that must change in order for a blink to be considered dangerous. Default value is 5, which means, a blink in a fifth of the screen will trigger the recognition, while value 1 is the whole screen. 
3. Important: Please ensure a deep testing before including this Epilepsy aid, warning the user about it. While false positives cause no harm, false negatives may happen for example due to actors, or even a third person character, intermittently blocking the light source of the blinking. This is one of the reasons the scene capture component is originally meant to be used statically in the map: as part of a player, linked to its moving camera, can be hard to tune in fast pacing games. It is better to aim it to the "potentially hazardous" scenes instead. 

# Future Machine Learning improvements

Some other solutions were studied while preparing this plugin, that are not included as they required extra infrastructue (and this plugin is meant to be standalone and offline). These solutions are:

1. Automatic Audio Descriptions. 
Google offers a decent [AI Audio Classifier](https://ai.google.dev/edge/mediapipe/solutions/audio/audio_classifier), in python, javascript and Android. Fortunately, Unreal UI Widget can load web components, so you can host a web service that receives the audio (or an audio stream) and returns the classifications as a list of probabilities. This is available as of now, as seen in the video example at the beginning of the page, but there are a couple of solvable problems you need to keep in mind:
   a. Google's classification model has a tendency to filter background noise. This may be a problem for atmospheric and quiet games/situations, as important low volume sounds will be completely ignored. A new model would have to be trained for such specific situations.
   b. The AI model is also very indicesive, changing its mind in fractions of a second, which can make tricky to offer a stable UI, readable for the player. This can be perhaps even harder in a model that does not filter background noises.
   c. If you decide not to send static audios, but instead the mix of the audio from the game, you'll find out the only way to allow this through web in Unreal is using the microphone. But the web component in Unreal doesn't offer CEF (Chromium Experiment Features), so the microphone permissions cannot be changed to enabled. Fortunately, there are (paid) Unreal web plugins out there that offers them.

2. Fast Neural Style Transfer
There is an official Neural Renderer plugin in UE5 that allows using ONNX models in post processing materials. For example those offered [here](https://github.com/onnx/models/tree/main/validated/vision/style_transfer/fast_neural_style), as seen in the video. While giving a glipmse of future capabilities, this is currently an experimental feature that cannot be deployed in production (the packaging of your project will fail if you attempt to use it), and that is currently stuck in old versions of ONNX and Pytorch.
