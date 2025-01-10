#pragma once

#include "Shape2D.h"

namespace qlexengine
{

    struct Square : public Shape2D
    {
        float size;

        Square(const maths::Vec2<float> &center_, const float &size_, Color color_) : size(size_), Shape2D(center_, color_) {};
        Square(const maths::Vec2<float> &center_, const float &size_, const float &mass_, Color color_) : size(size_), Shape2D(center_, mass_, color_) {};
        Square(const maths::Vec2<float> &center_, const float &size_, const maths::Vec2<float> &velocity_, const float &mass_, Color color_) : size(size_), Shape2D(center_, velocity_, mass_, color_) {};
        Square(const maths::Vec2<float> &center_, const float &size_, const maths::Vec2<float> &velocity_, const maths::Vec2<float> &force_, const float &mass_, Color color_) : size(size_), Shape2D(center_, velocity_, force_, mass_, color_) {};

        void update(const float &dt)
        {
            force = maths::Vec2<float>(0, 9.81f) * mass;
            velocity += force / mass * dt;
            center += velocity + dt;
            force = maths::Vec2<float>(0, 0); // reset net force at the end;
        }

        void draw() const
        {
            DrawRectangle(center.x, center.y, size, size, color);
        }

        maths::Vec2<float> getPosition() const
        {
            return center;
        }

        bool isPointInShape(const maths::Vec2<float> &point) const
        {
            return false;
        }

    private:
        std::unique_ptr<logger> _log = std::make_unique<logger>("Square");
    };

    inline std::ostream &operator<<(std::ostream &outs, const Square &s)
    {
        return outs << s.center << " c=" << s.size;
    }

} // qlexengine