#pragma once

#include "Shape.h"

namespace qlexengine
{

    struct Square : public Shape
    {
        float size;

        Square(const float &size_, const float &mass_) : size(size_), Shape(mass_) {};
        Square(const float &size_, const maths::Vec3<float> &position_, const float &mass_) : size(size_), Shape(position_, mass_) {};
        Square(const float &size_, const maths::Vec3<float> &position_, const maths::Vec3<float>& velocity_, const float &mass_) : size(size_), Shape(position_, velocity_, mass_) {};
    };

} // qlexengine