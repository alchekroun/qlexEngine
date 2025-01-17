#include <chrono>

#include "engine/Application.h"
#include "physics/dynamics/Circle.h"
#include "physics/dynamics/Rectangle.h"
#include "physics/dynamics/RigidBody.h"

namespace qlexengine
{

    bool Application::initialize()
    {
        _log->msg("Initialization...");
        _physicEngine->initialize();
        _renderer->initialize();
        _gui->initialize();
        _state = RUNNING;
        SetRandomSeed(std::chrono::system_clock::now().time_since_epoch().count());

        _log->msg("Initialization Done");
        return true;
    }

    void Application::createShapes()
    {

        auto center = maths::Vec2<float>(GetMouseX(), GetMouseY());
        auto velocity = maths::Vec2<float>(0, 0); // GetRandomValue(-10, 10), GetRandomValue(-10, 10));
        if (IsKeyPressed(KEY_A))
        {
            auto rectangleShape = std::make_shared<Rectangle>(GetRandomValue(50, 200), GetRandomValue(50, 200), 1.0);
            auto rectangleBody = std::make_shared<RigidBody>(center, rectangleShape, PURPLE);
            rectangleBody->id = _physicEngine->getRigidBodies().size();
            _physicEngine->addRigidBody(rectangleBody);
        }
        else if (IsKeyPressed(KEY_E))
        {
            auto circleShape = std::make_shared<Circle>(GetRandomValue(10, 200), 1.0);
            auto circleBody = std::make_shared<RigidBody>(center, circleShape, ORANGE);
            circleBody->id = _physicEngine->getRigidBodies().size();
            _physicEngine->addRigidBody(circleBody);
        }
    }

    bool Application::start(const float &dt)
    {
        InitWindow(_WINDOW_HEIGHT, _WINDOW_WIDTH, _WINDOW_HEADER_TEXT.c_str());
        SetTargetFPS(_FPS);

        _physicEngine->start();
        _renderer->start();
        _gui->start();

        std::shared_ptr<RigidBody> pSelectedRigidBody;
        Color oldColor;

        while (!WindowShouldClose())
        {
            float deltaTime = GetFrameTime();

            // User IO
            createShapes();

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                pSelectedRigidBody = nullptr;
                for (const auto &rb : _physicEngine->getRigidBodies())
                {
                    if (rb->isPointInShape(maths::Vec2<float>(GetMouseX(), GetMouseY())))
                    {
                        pSelectedRigidBody = rb;
                        oldColor = rb->color;
                        break;
                    }
                }
            }

            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                if (pSelectedRigidBody != nullptr)
                {
                    pSelectedRigidBody->color = BLACK;
                    pSelectedRigidBody->position.x = GetMouseX();
                    pSelectedRigidBody->position.y = GetMouseY();
                    pSelectedRigidBody->linearVelocity.x = 0;
                    pSelectedRigidBody->linearVelocity.y = 0;
                    pSelectedRigidBody->angularVelocity = 0;
                }
            }

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                if (pSelectedRigidBody != nullptr)
                    pSelectedRigidBody->color = oldColor;
                pSelectedRigidBody = nullptr;
            }

            // Update
            _physicEngine->update(deltaTime);

            // Drawing
            BeginDrawing();
            ClearBackground(RAYWHITE);
            _renderer->render(_physicEngine->getRigidBodies());
            // _renderer->renderCollisions(_physicEngine->getCollidingShapes());
            _gui->render(_physicEngine->getRigidBodies());

            DrawText(TextFormat("Mouse (%i,%i)", GetMouseX(), GetMouseY()), GetScreenWidth() - 115, 30, 15, DARKBLUE);
            DrawFPS(GetScreenWidth() - 95, 10);
            EndDrawing();
        }
        return true;
    }

    bool Application::stop()
    {
        _physicEngine->stop();
        _renderer->stop();
        _gui->stop();
        CloseWindow();
        return true;
    }

} // qlexengine