#include <chrono>

#include "engine/Application.h"

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

        // ImGui_ImplGlfw_InitForOpenGL( reinterpret_cast<GLFWwindow*>(GetWindowHandle()), true );
        _log->msg("Initialization Done");
        return true;
    }

    void Application::createShapes()
    {
        if (IsKeyPressed(KEY_A))
        {
            auto center = maths::Vec2<float>(GetMouseX(), GetMouseY());
            auto velocity = maths::Vec2<float>(0, 0); // GetRandomValue(-10, 10), GetRandomValue(-10, 10));
            auto tmpSquare = std::make_shared<Square>(center, GetRandomValue(50, 70), velocity, 1, PURPLE);
            _physicEngine->addShape2D(tmpSquare);
        }
        else if (IsKeyPressed(KEY_B))
        {
            auto center = maths::Vec2<float>(GetMouseX(), GetMouseY());
            auto velocity = maths::Vec2<float>(0, 0); // GetRandomValue(-10, 10), GetRandomValue(-10, 10));
            auto tmp_square = std::make_shared<Circle>(center, GetRandomValue(10, 200), velocity, 1, ORANGE);
            _physicEngine->addShape2D(tmp_square);
        }
        else if (IsKeyPressed(KEY_C))
        {
            auto center = maths::Vec2<float>(GetMouseX(), GetMouseY());
            auto velocity = maths::Vec2<float>(0, 0); // GetRandomValue(-10, 10), GetRandomValue(-10, 10));
            auto tmp_square = std::make_shared<Circle>(center, GetRandomValue(10, 200), velocity, 1, RED);
            _physicEngine->addShape2D(tmp_square);
        }
    }

    bool Application::start(const float &dt)
    {
        InitWindow(_WINDOW_HEIGHT, _WINDOW_WIDTH, _WINDOW_HEADER_TEXT.c_str());
        SetTargetFPS(_FPS);

        _physicEngine->start();
        _renderer->start();
        _gui->start();

        std::shared_ptr<Shape2D> pSelectedShape;
        Color oldColor;

        while (!WindowShouldClose())
        {
            float deltaTime = GetFrameTime();

            // User IO
            createShapes();

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                pSelectedShape = nullptr;
                for (const auto &s : _physicEngine->getShapes())
                {
                    if (s->isPointInShape(maths::Vec2<float>(GetMouseX(), GetMouseY())))
                    {
                        pSelectedShape = s;
                        oldColor = s->color;
                        break;
                    }
                }
            }

            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                if (pSelectedShape != nullptr)
                {
                    pSelectedShape->color = BLACK;
                    pSelectedShape->center.x = GetMouseX();
                    pSelectedShape->center.y = GetMouseY();
                    pSelectedShape->velocity.x = 0;
                    pSelectedShape->velocity.y = 0;
                }
            }

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                if (pSelectedShape != nullptr)
                    pSelectedShape->color = oldColor;
                pSelectedShape = nullptr;
            }

            // Update
            _physicEngine->update(deltaTime);

            // Drawing
            BeginDrawing();
            ClearBackground(RAYWHITE);
            _renderer->render(_physicEngine->getShapes());
            _gui->render(_physicEngine->getShapes());

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