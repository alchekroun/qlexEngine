#pragma once

#include <string>
#include <memory>

#include <raylib.h>

#include "logger/logger.h"
#include "maths/Vector2.h"

namespace qlexengine
{

    struct Shape2D
    {
        float mass;
        float momentOfInertia;

        virtual ~Shape2D() = default;

        virtual void draw(const maths::Vec2<float> &center_, const Color &color_, const float& rotation = 0.0) const = 0;
        virtual bool isPointInShape(const maths::Vec2<float> &center_, const maths::Vec2<float> &point_) const = 0;
    };

} // qlexengine