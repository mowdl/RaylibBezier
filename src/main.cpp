#include "raylib-cpp.hpp"
#include "Vector3.hpp"
#include "point.hpp"
#include <vector>
//


int main() {
    
    // Initialization
    int screenWidth = 1920;
    int screenHeight = 1080;

    raylib::Color textColor(LIGHTGRAY);
    raylib::Window w(screenWidth, screenHeight, "Raylib C++ Starter Kit Example");
    
    SetTargetFPS(60);

    Point point1{RED, Vector2{100, 100}};

    raylib::Vector2 center{screenWidth/2, screenHeight/2};



    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        // Update

        // TODO: Update your variables here

        // Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);
        textColor.DrawText("Congrats! You created your first window!", 190, 200, 20);
        textColor.DrawLineBezier(Vector2{1,1}, Vector2{1920, 1080}, 10.0f);
        
        point1.Draw();
        center.DrawCircle(100, BLACK);


        EndDrawing();
    }

    return 0;
}