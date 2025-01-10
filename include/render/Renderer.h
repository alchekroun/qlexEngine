#pragma once

#include <memory>
#include <vector>

#include <raylib.h>

#include "physics/Dynamics/Square.h"
#include "physics/Dynamics/Circle.h"
#include "physics/Dynamics/Triangle.h"

namespace qlexengine
{

    class Renderer
    {
    public:
        void initialize() {}
        void start() {}
        void stop() {}

        static void render(const std::vector<std::shared_ptr<Shape2D>> shapes_);

    private:
        inline static std::unique_ptr<logger> _log = std::make_unique<logger>("Renderer");
    };

} // qlexengine