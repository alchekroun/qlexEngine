#pragma once

#include <memory>
#include <vector>

#include <raylib.h>

#include "physics/Shape.h"
#include "physics/Square.h"

namespace qlexengine
{

class Renderer 
{
    public:
    template <typename T>
    static void drawShapes (const std::vector<std::shared_ptr<T>> shapes_)
    {
        static_assert(std::is_base_of_v<Shape, T>, "T must inherit from shape");
        for (const std::shared_ptr<T>& shape : shapes_)
        {

            if (Square* square = dynamic_cast<Square*>(shape.get()))
            {
                DrawRectangle(GetScreenHeight() - square->position.x, GetScreenWidth() - square->position.y, square->size, square->size, RED);
            }
        }
    };
};

} // qlexengine