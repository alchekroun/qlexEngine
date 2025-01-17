#pragma once

#include <memory>
#include <vector>

#include <raylib.h>

#include "physics/dynamics/RigidBody.h"

namespace qlexengine
{

    class Renderer
    {
    public:
        void initialize() {}
        void start() {}
        void stop() {}

        static void render(const std::vector<std::shared_ptr<RigidBody>> &rigidBodies_);

        static void renderCollisions(const std::vector<std::pair<std::shared_ptr<RigidBody>, std::shared_ptr<RigidBody>>> collidingShapes_);

    private:
        inline static std::unique_ptr<logger> _log = std::make_unique<logger>("Renderer");
    };

} // qlexengine