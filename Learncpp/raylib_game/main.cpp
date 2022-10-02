#include <iostream>
#include <string_view>

#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    constexpr int screenWidth{ 800 };
    constexpr int screenHeight{ 450 };
    constexpr int frameTarget{ 60 };
    constexpr std::string_view windowName{ "Raylib Game" };

    InitWindow(screenWidth, screenHeight, windowName);

    SetTargetFPS(frameTarget);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 200, screenHeight/2, 20, LIGHTGRAY);
        DrawCircle(200, 200, 10.0f, GREEN);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
