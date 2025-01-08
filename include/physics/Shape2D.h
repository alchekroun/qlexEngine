#pragma once

#include <string>
#include <memory>

#include "logger/logger.h"
#include "maths/Vector2.h"

namespace qlexengine
{

    struct Shape2D
    {
        maths::Vec2<float> velocity;
        maths::Vec2<float> force;
        float mass;

        Shape2D() : velocity(maths::Vec2<float>(0, 0)), force(maths::Vec2<float>(0, 0)), mass(0) {}
        Shape2D(const float &mass_) : velocity(maths::Vec2<float>(0, 0)), force(maths::Vec2<float>(0, 0)), mass(mass_) {}
        Shape2D(const maths::Vec2<float> &velocity_, const float &mass_) : velocity(velocity_), force(maths::Vec2<float>(0, 0)), mass(mass_) {}
        Shape2D(const maths::Vec2<float> &velocity_, const maths::Vec2<float> &force_, const float &mass_) : velocity(velocity_), force(force_), mass(mass_) {}

        virtual ~Shape2D() = default;

        virtual void update(const float &dt) = 0;
    };

} // qlexengine