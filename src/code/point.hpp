#include "raylib-cpp.hpp"

class Point
{
private:
    /* data */
    raylib::Color color;
    raylib::Vector2 position;
    float size;

public:
    Point(raylib::Color color, raylib::Vector2 position);
    Point(raylib::Color color, raylib::Vector2 position, float size);
    ~Point();

public:
    void Draw();
    static void DrawNew(raylib::Color drawColor, raylib::Vector2 drawPosition, float drawSize);
};



