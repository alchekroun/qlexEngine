#pragma once

#include "maths/Vector2.h"
#include "Shape2D.h"

namespace qlexengine
{
    struct RigidBody
    {
        maths::Vec2<float> position;
        maths::Vec2<float> linearVelocity;
        float angle;
        float angularVelocity;
        maths::Vec2<float> force;
        float torque;
        std::shared_ptr<Shape2D> shape;
        maths::Vec2<float> gravity{0, 9.81f};
        bool hasCollision = false;
        Color color;
        int id;

        RigidBody(
            const maths::Vec2<float> &position_,
            std::shared_ptr<Shape2D> shape_,
            const Color &color_) : position(position_),
                                   linearVelocity(maths::Vec2<float>::getZeroVec()),
                                   angle(0),
                                   angularVelocity(0),
                                   force(maths::Vec2<float>::getZeroVec()),
                                   torque(0),
                                   color(color_),
                                   shape(shape_)
        {
        }
        // RigidBody(const maths::Vec2<float> &position_, const Color &color_) : position(position_), Shape2D(position_, color_) {}

        void update(const float &dt)
        {
            force = gravity * shape->mass;
            maths::Vec2<float> armVector{0, 0};
            torque = armVector.x * force.y - armVector.y * force.x;

            linearVelocity += force / shape->mass * dt; // acceleration applied to velocity
            position += linearVelocity * dt;

            angularVelocity += torque / shape->momentOfInertia;
            angle += angularVelocity * dt;
        }

        void draw() const
        {
            shape->draw(position, color, angle);
        }

        bool isPointInShape(const maths::Vec2<float> &point_)
        {
            return shape->isPointInShape(position, point_);
        }
    };
} // qlexengine