#include "engine/Application.h"

namespace qlexengine
{

    bool Application::initialize()
    {
        return true;
    }

    bool Application::start(float dt)
    {
        for (int i = 0; i < 10; i++) {
            step(dt);
        }
        return true;
    }

    bool Application::removeShape2D(const std::shared_ptr<Shape2D> shape_)
    {
        auto shape_found = std::find(_shapes.begin(), _shapes.end(), shape_);
        if (shape_found != _shapes.end())
        {
            _shapes.erase(shape_found);
            return true;
        }
        return false;
    }

    void Application::step(float dt)
    {
        for (std::shared_ptr<Shape2D> shape : _shapes)
        {
            shape->update(dt);
        }
    }

} // qlexengine