/*
───────────────────────────────────────────────────────────────────────────────
  Author: KeesOG
───────────────────────────────────────────────────────────────────────────────
  Description:
  This DLL injects a thread into the process of the game to modify the player's
  gold value. It achieves this by:

  1. Identifying the base address for player data.
  2. Navigating through pointer chains to find the gold value.
  3. Creating a new thread that continuously checks for a specific key press
     ('M') to set the player's gold to 999.

  The functionality is implemented in the `injected_thread` function, which runs
  in an infinite loop, checking for the key press and updating the gold value.
───────────────────────────────────────────────────────────────────────────────
*/

#include <windows.h>

// Base address for the player data in memory
DWORD* player_base = (DWORD*)0x017EED18;

// Base address for the game, derived from player_base
DWORD* game_base = (DWORD*)(*player_base + 0xA90);

// Base address for the player's gold value, derived from game_base
DWORD* gold_base = (DWORD*)(*game_base + 0x4);

// Function to be run in the injected thread
void injected_thread() {
    while (true) {
        // Check if the 'M' key is pressed
        if (GetAsyncKeyState('M')) {
            // Set the player's gold value to 999
            *gold_base = 999;
        }
        // Sleep for a short duration to reduce CPU usage
        Sleep(1);
    }
}

// Entry point for the DLL application
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) {
    // Check the reason why DllMain is being called
    if (fdwReason == DLL_PROCESS_ATTACH) {
        // Create a new thread to run the injected_thread function
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)injected_thread, NULL, 0, NULL);
        // Show a message box (for debugging purposes)
        MessageBoxW(NULL, L"Injected DLL", L"Notification", MB_OK);
    }

    // Return TRUE to indicate successful initialization
    return TRUE;
}
