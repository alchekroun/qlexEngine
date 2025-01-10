#pragma once

#include "Shape2D.h"

namespace qlexengine
{

    struct Triangle : public Shape2D
    {
        maths::Vec2<float> a;
        maths::Vec2<float> b;
        maths::Vec2<float> c;

        Triangle(const maths::Vec2<float> &a_, const maths::Vec2<float> &b_, const maths::Vec2<float> &c_, Color color_) : a(a_), b(b_), c(c_), Shape2D(color_) {}
        Triangle(const maths::Vec2<float> &a_, const maths::Vec2<float> &b_, const maths::Vec2<float> &c_, const float &mass_, Color color_) : a(a_), b(b_), c(c_), Shape2D(mass_, color_) {}
        Triangle(const maths::Vec2<float> &a_, const maths::Vec2<float> &b_, const maths::Vec2<float> &c_, const maths::Vec2<float> &velocity_, const float &mass_, Color color_) : a(a_), b(b_), c(c_), Shape2D(velocity_, mass_, color_) {}
        Triangle(const maths::Vec2<float> &a_, const maths::Vec2<float> &b_, const maths::Vec2<float> &c_, const maths::Vec2<float> &velocity_, const maths::Vec2<float> &force_, const float &mass_, Color color_) : a(a_), b(b_), c(c_), Shape2D(velocity_, force_, mass_, color_) {}

        void update(const float &dt)
        {
            force = maths::Vec2<float>(0, -9.81f) * mass;
            velocity += force / mass * dt;
            a += velocity + dt;
            b += velocity + dt;
            c += velocity + dt;
            force = maths::Vec2<float>(0, 0); // reset net force at the end;
        };

        void draw() const
        {
            DrawTriangle(
                {GetScreenHeight() - a.x, GetScreenWidth() - a.y},
                {GetScreenHeight() - b.x, GetScreenWidth() - b.y},
                {GetScreenHeight() - c.x, GetScreenWidth() - c.y},
                color);
        }

        maths::Vec2<float> getPosition() const
        {
            return getIncenter();
        }

        maths::Vec2<float> getIncenter() const
        {
            float op_a = maths::distance(b, c);
            float op_b = maths::distance(a, c);
            float op_c = maths::distance(a, b);

            float perimeter = op_a + op_b + op_c;

            maths::Vec2<float> incenter(0, 0);
            incenter.x = (op_a * a.x + op_b * b.x + op_c * c.x) / perimeter;
            incenter.x = (op_a * a.y + op_b * b.y + op_c * c.y) / perimeter;

            return incenter;
        }

    private:
        std::unique_ptr<logger> _log = std::make_unique<logger>("Triangle");
    };

    inline std::ostream &operator<<(std::ostream &outs, const Triangle &t)
    {
        return outs << t.a << ' ' << t.b << ' ' << t.c;
    }

} // qlexengine