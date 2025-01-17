#pragma once

#include <memory>
#include <vector>
#include <utility>

#include "logger/logger.h"
#include "physics/dynamics/RigidBody.h"

namespace qlexengine
{
    class Engine
    {
    private:
        std::vector<std::shared_ptr<RigidBody>> _rigidBodies;
        std::vector<std::pair<std::shared_ptr<RigidBody>, std::shared_ptr<RigidBody>>> _collidingRigidBodies;

    public:
        void initialize() {}
        void start() {};
        void stop() {}
        bool update(const float &dt);

        void addRigidBody(const std::shared_ptr<RigidBody> shape_) { _rigidBodies.push_back(shape_); }
        bool removeRigidBody(const std::shared_ptr<RigidBody> shape_);
        std::vector<std::shared_ptr<RigidBody>> getRigidBodies() const { return _rigidBodies; }
        std::vector<std::pair<std::shared_ptr<RigidBody>, std::shared_ptr<RigidBody>>> getCollidingRigidBodies() const { return _collidingRigidBodies; }

        maths::Vec2<float> gravity2D{0, -9.81f};

        void detectCollisions();

        void solveCollisions();

    private:
        std::unique_ptr<logger> _log = std::make_unique<logger>("Engine");
    };
} // qlexengine