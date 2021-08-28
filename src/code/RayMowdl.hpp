#include "raylib-cpp.hpp"

namespace RayMowdl
{
    raylib::Vector2 MoveVector2DWithWASD(Vector2 position, float deltaTime, float speed)
    {
        raylib::Vector2 newPosition = position;
        newPosition.y += -(IsKeyDown(KEY_W) - IsKeyDown(KEY_S)) * speed * deltaTime; 
        newPosition.x += -(IsKeyDown(KEY_A) - IsKeyDown(KEY_D)) * speed * deltaTime; 
        return newPosition;
    }
    raylib::Vector2 MoveVector2DWithArrows(Vector2 position, float deltaTime, float speed)
    {
        raylib::Vector2 newPosition = position;
        newPosition.y += -(IsKeyDown(KEY_UP) - IsKeyDown(KEY_DOWN)) * speed * deltaTime; 
        newPosition.x += (IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT)) * speed * deltaTime; 
        return newPosition;
    }

    float MoveFloatWithMouseScroll(float value, float deltaTime, float speed)
    {
    }


}

