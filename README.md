# Multi Sensory Accessibility Plugin for Unreal Engine 5

### Aid for hearing loss, low vision, color blindness and epilepsy.

[![Video Title](https://img.youtube.com/vi/BThkBb_bR0w/0.jpg)](https://www.youtube.com/watch?v=BThkBb_bR0w)

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


    

