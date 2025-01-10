#pragma once

#include <sstream>
#include <memory>

#include "Shape2D.h"
#include "logger/logger.h"

namespace qlexengine
{

    struct Circle : public Shape2D
    {
        float radius;

        Circle(const maths::Vec2<float> &center_, const float &radius_, Color color_) : radius(radius_), Shape2D(center_, color_) {};
        Circle(const maths::Vec2<float> &center_, const float &radius_, const float &mass_, Color color_) : radius(radius_), Shape2D(center_, mass_, color_) {};
        Circle(const maths::Vec2<float> &center_, const float &radius_, const maths::Vec2<float> &velocity_, const float &mass_, Color color_) : radius(radius_), Shape2D(center_, velocity_, mass_, color_) {};
        Circle(const maths::Vec2<float> &center_, const float &radius_, const maths::Vec2<float> &velocity_, const maths::Vec2<float> &force_, const float &mass_, Color color_) : radius(radius_), Shape2D(center_, velocity_, force_, mass_, color_) {};

        void update(const float &dt)
        {
            force = maths::Vec2<float>(0, 9.81f) * mass;
            velocity += force / mass * dt;
            center += velocity + dt;
            force = maths::Vec2<float>(0, 0); // reset net force at the end;
        }

        void draw() const
        {
            DrawCircle(center.x, center.y, radius, color);
        }

        maths::Vec2<float> getPosition() const
        {
            return center;
        }

        bool isPointInShape(const maths::Vec2<float> &point) const
        {
            return maths::distance(point, center) < radius;
        }

    private:
        std::unique_ptr<logger> _log = std::make_unique<logger>("Circle");
    };

    inline std::ostream &operator<<(std::ostream &outs, const Circle &c)
    {
        return outs << c.center << " r=" << c.radius;
    }

} // qlexengine