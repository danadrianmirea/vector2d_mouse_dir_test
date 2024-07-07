/*******************************************************************************************
 *
 *   raylib [shapes] example - Vector Angle
 *
 *   Example originally created with raylib 1.0, last time updated with raylib 4.6
 *
 *   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
 *   BSD-like license that allows static linking with closed source software
 *
 *   Copyright (c) 2023 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/

#include "raylib.h"

#include "raymath.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [math] example - vector angle");

    Vector2 objPos = {screenWidth / 2, screenHeight / 2};
    Vector2 mousePos = {0}; // Updated with mouse position

    float angle;
    SetTargetFPS(144); // Set our game to run at 60 frames-per-second

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        mousePos = GetMousePosition();
        angle = Vector2LineAngle(objPos, mousePos) * RAD2DEG;

        BeginDrawing();
        ClearBackground(RAYWHITE);


        DrawRectanglePro(Rectangle{objPos.x, objPos.y - 5, 50, 10}, {0, 0}, -angle, RED);

        Vector2 dir = Vector2Add(mousePos, Vector2{-objPos.x,-objPos.y});
        dir = Vector2Normalize(dir);
        
        DrawLine(objPos.x, objPos.y, objPos.x + dir.x * 50, objPos.y + dir.y * 50, RED);
        
        EndDrawing();
    }

    //----------------------------------------------------------------------------------
    CloseWindow();
    return 0;
}