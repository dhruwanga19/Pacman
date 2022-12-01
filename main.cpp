#include "main.h"

//------------------------------------------------------------------------------------------
// Types and Structures Definition
//------------------------------------------------------------------------------------------
typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 672;
    const int screenHeight = 680;
    const char* titleText = "RASPMAN";

    GameScreen currentScreen = LOGO;

    InitWindow(screenWidth, screenHeight, "RASPMAN");
    InitAudioDevice();      	// Initialize audio device
    int framesCounter = 0;          // Useful to count frames
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    //Global Variables
    //--------------------------------------------------------------------------------------
    Audio audio_control;  // intialize the audio constructor
    audio_control.playAudio(0);  // play the background music
    
    // Maze map = Maze("DEFAULT_MAP.txt");
    // Sprite map_sprites = Sprite("./assets/maps/textures/DEFAULT_TEXTURE.png");
    GameManager manager = GameManager();
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        switch (currentScreen)
        {
        case LOGO:
        {
            // TODO: Update LOGO screen variables here!

            framesCounter++;    // Count frames

            // Wait for 2 seconds (120 frames) before jumping to TITLE screen
            if (framesCounter > 120)
            {
                currentScreen = TITLE;
            }
        } break;
        case TITLE:
        {
            // TODO: Update TITLE screen variables here!

            // Press enter to change to GAMEPLAY screen
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                currentScreen = GAMEPLAY;
            }
        } break;
        case GAMEPLAY:
        {
            // TODO: Update GAMEPLAY screen variables here!
             manager.update();
            // Press enter to change to ENDING screen
            // if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            // {
            //     currentScreen = ENDING;
            // }
        } break;
        case ENDING:
        {
            // TODO: Update ENDING screen variables here!

            // Press enter to return to TITLE screen
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                currentScreen = TITLE;
            }
        } break;
        default: break;
        }
        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        switch (currentScreen)
        {
        case LOGO:
        {
            // TODO: Draw LOGO screen here!
            DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
            DrawText("WAIT for 2 SECONDS...", 290, 220, 20, WHITE);

        } break;
        case TITLE:
        {
            // TODO: Draw TITLE screen here!
            Vector2 textOffset = MeasureTextEx(GetFontDefault(), titleText, 20, 0);
            Vector2 textPos{ (screenWidth / 2) - textOffset.x, (screenHeight / 2) - textOffset.y };
            DrawTextEx(GetFontDefault(), titleText, textPos, 20, 10, WHITE);

        } break;
        case GAMEPLAY:
        {
            // TODO: Draw GAMEPLAY screen here!
            //map.drawMazeEX(map_sprites);
            // map.drawMaze();

        } break;
        case ENDING:
        {
            // TODO: Draw ENDING screen here!
            DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
            DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);

        } break;
        default: break;
        }

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
