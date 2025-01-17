#pragma once

#include "maths/Vector2.h"

namespace qlexengine
{
    struct transform
    {
        maths::Vec2<float> position;
        maths::Vec2<float> scale;
        maths::Vec2<float> rotation;
    };
} // qlexengine