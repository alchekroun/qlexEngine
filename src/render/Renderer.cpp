#include "render/Renderer.h"

namespace qlexengine
{
    void Renderer::initialize()
    {
        InitWindow(_WINDOW_HEIGHT, _WINDOW_WIDTH, _WINDOW_HEADER_TEXT.c_str());
        SetTargetFPS(_FPS);
    }

    void Renderer::start()
    {
    }

    void Renderer::stop()
    {
    }

    void Renderer::drawShapes(const std::vector<std::shared_ptr<Shape2D>> shapes_)
    {
        for (const auto &shape : shapes_)
        {
            shape->draw();
        }
    }

} // qlexengine