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

        Circle(const float &radius_) : Circle(radius_, 0.0) {}
        Circle(const float &radius_, const float &mass_) : radius(radius_)
        {
            mass = mass_;
            momentOfInertia = M_PI * std::pow(radius, 4) / 4;
        }

        void draw(const maths::Vec2<float> &center_, const Color &color_, const float &rotation_ = 0.0) const
        {
            DrawCircle(center_.x, center_.y, radius, color_);
            DrawCircle(center_.x, center_.y, 2, BLACK);
        }

        bool isPointInShape(const maths::Vec2<float> &center_, const maths::Vec2<float> &point_) const
        {
            return maths::distance(point_, center_) < radius;
        }

    private:
        std::unique_ptr<logger> _log = std::make_unique<logger>("Circle");
    };

    inline std::ostream &operator<<(std::ostream &outs, const Circle &c)
    {
        return outs << " r=" << c.radius;
    }

} // qlexengine