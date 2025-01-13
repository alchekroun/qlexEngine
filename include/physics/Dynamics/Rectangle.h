#pragma once

#include "Shape2D.h"

namespace qlexengine
{

    struct Rectangle : public Shape2D
    {
        float width;
        float height;
        // TODO : Rework square as rectangle
        Rectangle(const maths::Vec2<float> &center_, const float &width_, const float &height_, Color color_) : width(width_), height(height_), Shape2D(center_, color_) {};
        Rectangle(const maths::Vec2<float> &center_, const float &width_, const float &height_, const float &mass_, Color color_) : width(width_), height(height_), Shape2D(center_, mass_, color_) {};
        Rectangle(const maths::Vec2<float> &center_, const float &width_, const float &height_, const maths::Vec2<float> &velocity_, const float &mass_, Color color_) : width(width_), height(height_), Shape2D(center_, velocity_, mass_, color_) {};
        Rectangle(const maths::Vec2<float> &center_, const float &width_, const float &height_, const maths::Vec2<float> &velocity_, const maths::Vec2<float> &force_, const float &mass_, Color color_) : width(width_), height(height_), Shape2D(center_, velocity_, force_, mass_, color_) {};

        void update(const float &dt)
        {
            force = maths::Vec2<float>(0, 9.81f) * mass;
            velocity += force / mass * dt;
            center += velocity + dt;
            force = maths::Vec2<float>(0, 0); // reset net force at the end;
        }

        void draw() const
        {
            DrawCircle(center.x, center.y, 2, BLACK);
            // DrawRectangle's center X & Y are NOT the center, where rectangle's diagonals cross,
            // but the top left corner.
            DrawRectangle(center.x, center.y, width, height, color);
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
        std::unique_ptr<logger> _log = std::make_unique<logger>("Rectangle");
    };

    inline std::ostream &operator<<(std::ostream &outs, const Rectangle &s)
    {
        return outs << s.center << " w=" << s.width << " h=" << s.height;
    }

} // qlexengine