#include "render/Renderer.h"

namespace qlexengine
{

    void Renderer::render(const std::vector<std::shared_ptr<RigidBody>> &rigidBodies_)
    {
        for (const auto &rigidBody : rigidBodies_)
        {
            rigidBody->draw();
        }
    }
    /*
        void Renderer::renderCollisions(const std::vector<std::pair<std::shared_ptr<RigidBody>, std::shared_ptr<RigidBody>>> collidingShapes_)
        {
            for (const auto &[s1, s2] : collidingShapes_)
            {
                DrawLine(s1->center.x, s1->center.y, s2->center.x, s2->center.y, RED);
            }
        }
    */
} // qlexengine