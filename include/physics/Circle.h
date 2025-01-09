#pragma once

#include <sstream>
#include <memory>

#include "Shape2D.h"
#include "logger/logger.h"

namespace qlexengine
{

    struct Circle : public Shape2D
    {
        maths::Vec2<float> center;
        float radius;

        Circle(const maths::Vec2<float> &center_, const float &radius_, Color color_) : center(center_), radius(radius_), Shape2D(color_) {};
        Circle(const maths::Vec2<float> &center_, const float &radius_, const float &mass_, Color color_) : center(center_), radius(radius_), Shape2D(mass_, color_) {};
        Circle(const maths::Vec2<float> &center_, const float &radius_, const maths::Vec2<float> &velocity_, const float &mass_, Color color_) : center(center_), radius(radius_), Shape2D(velocity_, mass_, color_) {};
        Circle(const maths::Vec2<float> &center_, const float &radius_, const maths::Vec2<float> &velocity_, const maths::Vec2<float> &force_, const float &mass_, Color color_) : center(center_), radius(radius_), Shape2D(velocity_, force_, mass_, color_) {};

        void update(const float &dt)
        {
            force = maths::Vec2<float>(0, -9.81f) * mass;
            velocity += force / mass * dt;
            center += velocity + dt;
            force = maths::Vec2<float>(0, 0); // reset net force at the end;
        }

        void draw()
        {
            DrawCircle(GetScreenHeight() - center.x, GetScreenWidth() - center.y, radius, color);
        }

    private:
        std::unique_ptr<logger> _log = std::make_unique<logger>("Circle");
    };

    inline std::ostream &operator<<(std::ostream &outs, const Circle &c)
    {
        return outs << c.center << " r=" << c.radius;
    }

} // qlexengine