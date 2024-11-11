# 🏰 Wesnoth Hack by KeesOG 🎮

## Overview
Welcome to the Wesnoth Hack repository! This project features a dynamic link library (DLL) hack for the game "Battle for Wesnoth," engineered to boost your gold value by injecting a custom thread directly into the game's process. 🪄

## ✨ Features
- **💰 Dynamic Gold Modification:** Press the magical 'M' key to instantly set your gold to 999, granting you a strategic edge.
- **🕵️‍♂️ Real-Time Monitoring:** Our vigilant thread keeps an eye out for the 'M' key press to update your gold in real-time.
- **🎮 Seamless Integration:** Activate the hack effortlessly with a simple key press, ensuring uninterrupted gameplay.

## ⚙️ Technical Details
### 🧠 Memory Address Resolution
1. **Player Base Address Identification:**
   - The player's data base address is a constant pointer at `0x017EED18`, serving as the launch point for accessing player-specific memory data.

2. **Navigating Pointer Chains:**
   - From `player_base`, compute `game_base` by dereferencing `player_base` and adding `0xA90`.
   - Locate the player's gold value address, `gold_base`, by further dereferencing `game_base` and adding `0x4`.

### 🛠️ Thread Injection and Memory Manipulation
1. **Thread Injection:**
   - Upon DLL load, create a new thread with `CreateThread`. This thread runs `injected_thread`, looping indefinitely.

2. **Memory Manipulation:**
   - `injected_thread` monitors the 'M' key state using `GetAsyncKeyState`.
   - When 'M' is pressed, it updates the gold value at `gold_base` to `999`.

## 🚀 Installation
1. **Compile the DLL:**
   - Use a C++ compiler to compile the source code into a DLL file.
2. **Inject the DLL:**
   - Utilize a DLL injector to inject the compiled DLL into the Battle for Wesnoth process.
3. **Activate the Hack:**
   - During gameplay, press the 'M' key to set your gold to 999.

## ⚠️ Disclaimer
Use this hack at your own risk. Modifying game memory can lead to unpredictable behavior and may violate the game's terms of service. Always back up your game data before using hacks or modifications.

## 📜 License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
