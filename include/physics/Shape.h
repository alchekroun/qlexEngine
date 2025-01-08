#pragma once

#include "maths/Vector3.h"

namespace qlexengine
{

struct Shape
{
    maths::Vec3<float> position;
    maths::Vec3<float> velocity;
    maths::Vec3<float> force;
    float mass;

    Shape(const float& mass_) : position(maths::Vec3<float>(0, 0, 0)), velocity(maths::Vec3<float>(0, 0, 0)), force(maths::Vec3<float>(0, 0, 0)), mass(mass_) {}
    Shape(const maths::Vec3<float>& position_, const float& mass_) : position(position_), velocity(maths::Vec3<float>(0, 0, 0)), force(maths::Vec3<float>(0, 0, 0)), mass(mass_) {}
    Shape(const maths::Vec3<float>& position_, const maths::Vec3<float>& velocity_, const float& mass_) : position(position_), velocity(velocity_), force(maths::Vec3<float>(0, 0, 0)), mass(mass_) {}

    virtual ~Shape() = default;
};



} // qlexengine