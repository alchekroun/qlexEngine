#pragma once

#include "Shape2D.h"

namespace qlexengine
{

    struct Square : public Shape2D
    {
        maths::Vec2<float> center;
        float size;

        Square(const maths::Vec2<float> &center_, const float &size_) : center(center_), size(size_), Shape2D() {};
        Square(const maths::Vec2<float> &center_, const float &size_, const float &mass_) : center(center_), size(size_), Shape2D(mass_) {};
        Square(const maths::Vec2<float> &center_, const float &size_, const maths::Vec2<float> &velocity_, const float &mass_) : center(center_), size(size_), Shape2D(velocity_, mass_) {};
        Square(const maths::Vec2<float> &center_, const float &size_, const maths::Vec2<float> &velocity_, const maths::Vec2<float> &force_, const float &mass_) : center(center_), size(size_), Shape2D(velocity_, force_, mass_) {};

        void update(const float &dt)
        {
            force = maths::Vec2<float>(0, -9.81f) * mass;
            velocity += force / mass * dt;
            center += velocity + dt;
            force = maths::Vec2<float>(0, 0); // reset net force at the end;
        }

        std::unique_ptr<logger> _log = std::make_unique<logger>("Square");
    };

    std::ostream &operator<<(std::ostream &outs, const Square &s)
    {
        return outs << s.center << " c=" << s.size;
    }

} // qlexengine