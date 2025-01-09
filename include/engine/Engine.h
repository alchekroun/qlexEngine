#pragma once

#include <memory>
#include <vector>

#include "logger/logger.h"
#include "physics/Shape2D.h"

namespace qlexengine
{
    class Engine
    {
    private:
        std::vector<std::shared_ptr<Shape2D>> _shapes;

    public:
        void initialize() {}
        void start() {};
        void stop() {}
        bool update(const float &dt);

        void addShape2D(const std::shared_ptr<Shape2D> shape_) { _shapes.push_back(shape_); }
        bool removeShape2D(const std::shared_ptr<Shape2D> shape_);
        std::vector<std::shared_ptr<Shape2D>> getShapes() const { return _shapes; }

        maths::Vec2<float> gravity2D{0, -9.81f};

    private:
        std::unique_ptr<logger> _log = std::make_unique<logger>("Engine");
    };
} // qlexengine