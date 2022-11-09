#include <raylib.h>
#include <raymath.h>
#include "Audio.h"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 672;
    const int screenHeight = 864;
    const char* testText = "RASPMAN";

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    InitAudioDevice();      	// Initialize audio device
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    //Global Variables
    //--------------------------------------------------------------------------------------
    //
    Audio audio_control;  // intialize the audio constructor
    audio_control.playAudio(0);  // play the background music
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_SPACE)) audio_control.playAudio(1);
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);
        Vector2 textOffset = MeasureTextEx(GetFontDefault(), testText, 20, 0);
        Vector2 textPos{ (screenWidth / 2) - textOffset.x, (screenHeight / 2) - textOffset.y };
        DrawTextEx(GetFontDefault(), testText, textPos, 20, 10, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseAudioDevice();   // Close audio device
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
