#include "point.hpp"

Point::Point(raylib::Color color, raylib::Vector2 position) : color(color), position(position), size(1.0f) {}
Point::Point(raylib::Color color, raylib::Vector2 position, float size) : color(color), position(position), size(size) {}
Point::~Point(){};

void Point::Draw()
{
    position.DrawCircle(15.0f * size, color);
    position.DrawCircle(11.0f * size, BLACK);
}


void Point::DrawNew(raylib::Color drawColor, raylib::Vector2 drawPosition, float drawSize)
{
    drawPosition.DrawCircle(15.0f * drawSize, drawColor);
    drawPosition.DrawCircle(11.0f * drawSize, BLACK);
}
    