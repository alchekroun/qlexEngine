#pragma once

#include "maths/Vector2.h"

namespace qlexengine
{
    struct ContactPoint
    {
        maths::Vec2<float> position;
        float penetration_depth;
    };

    struct ContactManifold
    {
        int pointCount;
        ContactPoint points[2]; // 2D
        maths::Vec2<float> normal;
    };
}