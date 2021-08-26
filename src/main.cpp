#include "raylib-cpp.hpp"
#include "Vector3.hpp"
#include "point.hpp"
#include <vector>

#include <iostream>


int main() {
    
    // Initialization
    int screenWidth = 1920;
    int screenHeight = 1080;

    raylib::Color textColor(LIGHTGRAY);
    raylib::Window w(screenWidth, screenHeight, "Raylib C++ Starter Kit Example");
    
    SetTargetFPS(60);

    SetGesturesEnabled(GESTURE_DRAG);

    Point point1{RED, Vector2{100, 100}};
    Point point2{RED, Vector2{300, 300}};
    Point point3{RED, Vector2{300, 900}};

    raylib::Vector2 center{float(screenWidth)/2, float(screenHeight)/2};

    float t = 0.0f;



    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        // Update
        float deltaTime = w.GetFrameTime();

        point1.Update();
        point2.Update();
        point3.Update();

        raylib::Vector2 lerped1 = point1.position.Lerp(point2.position, t);
        raylib::Vector2 lerped2 = point2.position.Lerp(point3.position, t);
        raylib::Vector2 lerped3 = lerped1.Lerp(lerped2, t);

        t += deltaTime * 0.1f   ;
        t = t * (t < 1);

        // Draw
        BeginDrawing();

        raylib::Color(RED).DrawText("Draw", 1000, 1000, 20);

        DrawFPS(10, 10);

        ClearBackground(RAYWHITE);
        textColor.DrawText("Congrats! You created your first window!", 190, 200, 20);
        textColor.DrawLineBezier(Vector2{1,1}, Vector2{1920, 1080}, 10.0f);

        point1.Draw();
        point2.Draw();
        point3.Draw();

        Point::DrawNew(BLACK, lerped1, 0.5f);        
        Point::DrawNew(BLACK, lerped2, 0.5f);        

        Point::DrawNew(BLUE, lerped3, 1.5f);

        EndDrawing();
    }

    return 0;
}