#include "render/Renderer.h"

namespace qlexengine
{

    void Renderer::render(const std::vector<std::shared_ptr<Shape2D>> shapes_)
    {
        for (const auto &shape : shapes_)
        {
            shape->draw();
        }
    }

} // qlexengine