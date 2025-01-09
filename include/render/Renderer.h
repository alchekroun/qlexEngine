#pragma once

#include <memory>
#include <vector>

#include <raylib.h>

#include "physics/Square.h"
#include "physics/Circle.h"
#include "physics/Triangle.h"

namespace qlexengine
{

    class Renderer
    {
    public:
        void initialize();
        void start();
        void stop();

        static void drawShapes(const std::vector<std::shared_ptr<Shape2D>> shapes_);

    private:
        inline static int _FPS = 60;
        inline static int _WINDOW_HEIGHT = 800;
        inline static int _WINDOW_WIDTH = 600;
        inline static std::string _WINDOW_HEADER_TEXT = "qlexEngine - Test Zone";

        inline static std::unique_ptr<logger> _log = std::make_unique<logger>("Renderer");
    };

} // qlexengine