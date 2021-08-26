#include "point.hpp"

#include <iostream>


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
    
void Point::Update()
{
    raylib::Color(RED).DrawText("Update", 1000, 1020, 20);
    this->GetDraged();
}

void Point::MoveToMouse()
{
    position = GetMousePosition();
}

void Point::GetDraged()
{
    if (IsGestureDetected(GESTURE_DRAG))
    {
        if (isBeingDragged)
        {
            MoveToMouse();
        }
        else if (position.Distance(GetMousePosition()) < 10 * size)
        {
            MoveToMouse();
            isBeingDragged = true;
        }

    }
    else
    {
        isBeingDragged = false;
    }
}