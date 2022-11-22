#include "raylib.h"
#include "raymath.h"
#include "Audio.h"
#include "Maze.h"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 672;
    const int screenHeight = 680;
    const char* testText = "RASPMAN";

    InitWindow(screenWidth, screenHeight, "RASPMAN");
    InitAudioDevice();      	// Initialize audio device
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    //Global Variables
    //--------------------------------------------------------------------------------------
    Audio audio_control;  // intialize the audio constructor
    audio_control.playAudio(0);  // play the background music
    Maze map = Maze("DEFAULT_MAP.txt");
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

        // Draw the Map
        //Maze map = Maze("DEFAULT_MAP.txt");
        //Maze map = Maze();
        //map.drawMaze();
        map.drawMazeEX();

        //Draw Title
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
