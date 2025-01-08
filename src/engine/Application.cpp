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

    bool Application::removeShape(const std::shared_ptr<Shape> shape_)
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
        for (std::shared_ptr<Shape> shape : _shapes)
        {
            _log->msg("Before : ", shape->position);
            shape->force = _gravity * shape->mass;

            shape->velocity += shape->force / shape->mass * dt;
            shape->position += shape->velocity * dt;
            shape->force = maths::Vec3<float>(0, 0, 0); // reset net force at the end;
            _log->msg("After +", dt, " : ", shape->position);
        }
    }

} // qlexengine