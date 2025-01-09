#include "engine/Engine.h"

namespace qlexengine
{

    bool Engine::removeShape2D(const std::shared_ptr<Shape2D> shape_)
    {
        auto shape_found = std::find(_shapes.begin(), _shapes.end(), shape_);
        if (shape_found != _shapes.end())
        {
            _shapes.erase(shape_found);
            return true;
        }
        return false;
    }

    bool Engine::update(const float &dt)
    {
        for (std::shared_ptr<Shape2D> shape : _shapes)
        {
            shape->update(dt);
        }
        return true;
    }

} // qlexengine