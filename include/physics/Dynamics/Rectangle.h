#pragma once

#include "Shape2D.h"

namespace qlexengine
{

    struct Rectangle : public Shape2D
    {
        float width;
        float height;

        Rectangle(const float &width_, const float &height_) : Rectangle(width_, height_, 0.0) {}
        Rectangle(const float &width_, const float &height_, const float &mass_) : width(width_), height(height_)
        {
            mass = mass_;
            momentOfInertia = mass_ * (width_ * width_ + height_ * height_) / 12;
        }

        maths::Vec2<float> getTopLeftCorner(const maths::Vec2<float> &center_) const
        {
            return maths::Vec2<float>{center_.x - width / 2, center_.y - height / 2};
        }

        maths::Vec2<float> getTopRightCorner(const maths::Vec2<float> &center_) const
        {
            return maths::Vec2<float>{center_.x + width / 2, center_.y - height / 2};
        }

        maths::Vec2<float> getBottomRightCorner(const maths::Vec2<float> &center_) const
        {
            return maths::Vec2<float>{center_.x + width / 2, center_.y + height / 2};
        }

        void draw(const maths::Vec2<float> &center_, const Color &color_, const float &rotation_) const
        {
            // DrawRectangle's center X & Y are NOT the center, where rectangle's diagonals cross,
            // but the top left corner.
            auto topLeftCorner = getTopLeftCorner(center_);
            DrawRectangle(topLeftCorner.x, topLeftCorner.y, width, height, color_);
            DrawCircle(center_.x, center_.y, 2, BLACK);
        }

        bool isPointInShape(const maths::Vec2<float> &center_, const maths::Vec2<float> &point_) const
        {
            auto A = getTopLeftCorner(center_);
            auto B = getTopRightCorner(center_);
            auto C = getBottomRightCorner(center_);
            auto AB = A - B;
            auto AC = A - C;
            auto AP = A - point_;
            auto BC = B - C;
            auto BP = B - point_;

            return (
                (0 <= maths::dotProduct(AB, AP) <= maths::dotProduct(AB, AB)) &&
                (0 <= maths::dotProduct(BC, BP) <= maths::dotProduct(BC, BC)));
        }

    private:
        std::unique_ptr<logger> _log = std::make_unique<logger>("Rectangle");
    };

    inline std::ostream &operator<<(std::ostream &outs, const Rectangle &s)
    {
        return outs << "w=" << s.width << " h=" << s.height;
    }

} // qlexengine