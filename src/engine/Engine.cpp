#include "engine/Engine.h"

namespace qlexengine
{

    bool Engine::removeRigidBody(const std::shared_ptr<RigidBody> rigidBody_)
    {
        auto rigidBody_found = std::find(_rigidBodies.begin(), _rigidBodies.end(), rigidBody_);
        if (rigidBody_found != _rigidBodies.end())
        {
            _rigidBodies.erase(rigidBody_found);
            return true;
        }
        return false;
    }

    bool Engine::update(const float &dt)
    {
        for (std::shared_ptr<RigidBody> rigidBody : _rigidBodies)
        {
            // detectCollisions();
            rigidBody->update(dt);
        }
        return true;
    }
    /*
        void Engine::detectCollisions()
        {
            for (std::shared_ptr<RigidBody> rigidBody : _rigidBodies)
            {
                Circle *c = dynamic_cast<Circle *>(rigidBody.get());
                if (c == nullptr)
                    continue;

                for (std::shared_ptr<RigidBody> target : _rigidBodies)
                {
                    Circle *c_target = dynamic_cast<Circle *>(target.get());
                    if (c_target == nullptr)
                        continue;

                    if (c == c_target)
                        continue;

                    if (c->doCircleOverlap(*c_target))
                    {
                        c->hasColision = true;
                        c_target->hasColision = true;

                        float distance = maths::distance(c->center, c_target->center);

                        float overlap = distance - c->radius - c_target->radius;

                        c->center.x -= (overlap * 0.5) * (c->center.x - c_target->center.x) / distance;
                        c->center.y -= (overlap * 0.5) * (c->center.y - c_target->center.y) / distance;

                        c_target->center.x += (overlap * 0.5) * (c->center.x - c_target->center.x) / distance;
                        c_target->center.y += (overlap * 0.5) * (c->center.y - c_target->center.y) / distance;
                    }
                    else
                    {
                        c->hasColision = false;
                        c_target->hasColision = false;
                    }
                }
            }
            return;
        }

        void Engine::solveCollisions()
        {
            for (const auto &[s1, s2] : _collidingRigidBodies)
            {
                // if (s1)
            }
        }
    */
} // qlexengine