#include <iostream>

#include "logger/logger.h"
#include "physics/Square.h"
#include "physics/Circle.h"
#include "engine/Application.h"
#include "render/Renderer.h"

#include <raylib.h>

std::unique_ptr<qlexengine::logger> _log = std::make_unique<qlexengine::logger>("MAIN");

int main()
{
    qlexengine::Application *a = new qlexengine::Application();
    a->initialize();
    std::shared_ptr<qlexengine::Square> s1 = std::make_shared<qlexengine::Square>(qlexengine::maths::Vec2<float>(400, 400), 50, 1.0, PURPLE);
    std::shared_ptr<qlexengine::Square> s2 = std::make_shared<qlexengine::Square>(qlexengine::maths::Vec2<float>(0, 400), 50, qlexengine::maths::Vec2<float>(5, 0), 1.0, RED);
    std::shared_ptr<qlexengine::Circle> c1 = std::make_shared<qlexengine::Circle>(qlexengine::maths::Vec2<float>(0, 600), 50, qlexengine::maths::Vec2<float>(5, 0), 1.0, BLUE);
    std::shared_ptr<qlexengine::Triangle> t1 = std::make_shared<qlexengine::Triangle>(qlexengine::maths::Vec2<float>(100, 100), qlexengine::maths::Vec2<float>(100, 200), qlexengine::maths::Vec2<float>(200, 200), qlexengine::maths::Vec2<float>(2, 15), 0.01, GREEN);

    a->_physicEngine->addShape2D(s1);
    a->_physicEngine->addShape2D(s2);
    a->_physicEngine->addShape2D(c1);
    a->_physicEngine->addShape2D(t1);

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();

        a->_physicEngine->update(deltaTime);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("SEPT heures cumulés pour afficher ça!", 200, 200, 20, BLACK);
        qlexengine::Renderer::drawShapes(a->_physicEngine->getShapes());
        EndDrawing();
    }

    CloseWindow();
    return 0;
}