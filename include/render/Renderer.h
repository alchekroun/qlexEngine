#pragma once

#include <memory>
#include <vector>

#include <raylib.h>

#include "physics/dynamics/Shape2D.h"

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