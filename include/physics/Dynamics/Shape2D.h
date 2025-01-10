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
        maths::Vec2<float> center;
        maths::Vec2<float> velocity;
        maths::Vec2<float> force;
        float mass;
        Color color;

        Shape2D(const maths::Vec2<float> &center_, Color color_) : center(center_), velocity(maths::Vec2<float>(0, 0)), force(maths::Vec2<float>(0, 0)), mass(0), color(color_) {}
        Shape2D(const maths::Vec2<float> &center_, const float &mass_, Color color_) : center(center_), velocity(maths::Vec2<float>(0, 0)), force(maths::Vec2<float>(0, 0)), mass(mass_), color(color_) {}
        Shape2D(const maths::Vec2<float> &center_, const maths::Vec2<float> &velocity_, const float &mass_, Color color_) : center(center_), velocity(velocity_), force(maths::Vec2<float>(0, 0)), mass(mass_), color(color_) {}
        Shape2D(const maths::Vec2<float> &center_, const maths::Vec2<float> &velocity_, const maths::Vec2<float> &force_, const float &mass_, Color color_) : center(center_), velocity(velocity_), force(force_), mass(mass_), color(color_) {}

        virtual ~Shape2D() = default;

        virtual void update(const float &dt) = 0;
        virtual void draw() const = 0;
        virtual maths::Vec2<float> getPosition() const = 0;
        virtual bool isPointInShape(const maths::Vec2<float> &point) const = 0;
    };

} // qlexengine