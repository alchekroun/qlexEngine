#pragma once

#include <memory>
#include <vector>

#include <raylib.h>

#include "physics/Shape2D.h"
#include "physics/Square.h"
#include "physics/Circle.h"
#include "physics/Triangle.h"

namespace qlexengine
{

class Renderer 
{
    public:
    template <typename T>
    static void drawShapes (const std::vector<std::shared_ptr<T>> shapes_)
    {
        static_assert(std::is_base_of_v<Shape2D, T>, "T must inherit from shape");
        for (const std::shared_ptr<T>& shape : shapes_)
        {

            if (Square* square = dynamic_cast<Square*>(shape.get()))
            {
                DrawRectangle(GetScreenHeight() - square->center.x, GetScreenWidth() - square->center.y, square->size, square->size, RED);
            } else if (Circle* circle = dynamic_cast<Circle*>(shape.get()))
            {
                DrawCircle(GetScreenHeight() - circle->center.x, GetScreenWidth() - circle->center.y, circle->radius, GREEN);
            } else if (Triangle* triangle = dynamic_cast<Triangle*>(shape.get()))
            {
                DrawTriangle(
                    {GetScreenHeight() - triangle->a.x, GetScreenWidth() - triangle->a.y},
                    {GetScreenHeight() - triangle->b.x, GetScreenWidth() - triangle->b.y},
                    {GetScreenHeight() - triangle->c.x, GetScreenWidth() - triangle->c.y},
                    PURPLE);
            }
        }
    };

    private:
    inline static std::unique_ptr<logger> _log = std::make_unique<logger>("Renderer");
};

} // qlexengine