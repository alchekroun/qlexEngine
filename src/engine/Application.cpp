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

    bool Application::start(const float &dt)
    {
        InitWindow(_WINDOW_HEIGHT, _WINDOW_WIDTH, _WINDOW_HEADER_TEXT.c_str());
        SetTargetFPS(_FPS);

        _physicEngine->start();
        _renderer->start();
        _gui->start();

        while (!WindowShouldClose())
        {
            float deltaTime = GetFrameTime();

            // User IO
            if (IsKeyPressed(KEY_A))
            {
                auto center = qlexengine::maths::Vec2<float>(GetScreenHeight() - GetMouseX(), GetScreenWidth() - GetMouseY());
                auto velocity = qlexengine::maths::Vec2<float>(GetRandomValue(-10, 10), GetRandomValue(-10, 10));
                auto tmp_square = std::make_shared<qlexengine::Square>(center, GetRandomValue(10, 200), velocity, GetRandomValue(1, 2), PURPLE);
                _physicEngine->addShape2D(tmp_square);
            }
            else if (IsKeyPressed(KEY_B))
            {
                auto center = qlexengine::maths::Vec2<float>(GetScreenHeight() - GetMouseX(), GetScreenWidth() - GetMouseY());
                auto velocity = qlexengine::maths::Vec2<float>(GetRandomValue(-10, 10), GetRandomValue(-10, 10));
                auto tmp_square = std::make_shared<qlexengine::Circle>(center, GetRandomValue(10, 200), velocity, GetRandomValue(1, 2), ORANGE);
                _physicEngine->addShape2D(tmp_square);
            }
            else if (IsKeyPressed(KEY_C))
            {
                auto center = qlexengine::maths::Vec2<float>(GetScreenHeight() - GetMouseX(), GetScreenWidth() - GetMouseY());
                auto velocity = qlexengine::maths::Vec2<float>(GetRandomValue(-10, 10), GetRandomValue(-10, 10));
                auto tmp_square = std::make_shared<qlexengine::Circle>(center, GetRandomValue(10, 200), velocity, GetRandomValue(1, 2), ORANGE);
                _physicEngine->addShape2D(tmp_square);
            }

            // Update
            _physicEngine->update(deltaTime);

            // Drawing
            BeginDrawing();
            ClearBackground(RAYWHITE);
            _renderer->render(_physicEngine->getShapes());
            _gui->render(_physicEngine->getShapes());
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