#include <iostream>

#include "logger/logger.h"
#include "physics/Square.h"
#include "engine/Application.h"
#include "render/Renderer.h"

#include <raylib.h>

qlexengine::logger *_log = new qlexengine::logger("MAIN");

int main()
{
    /*     qlexengine::maths::Vec3<int>* v1 = new qlexengine::maths::Vec3<int>(0, 0, 0);
        _log->msg("x = ", v1->x);
        *v1 += 1;
        _log->msg("x = ", v1->x);

        qlexengine::Shape* s1 = new qlexengine::Shape(1.0);
        _log->msg("s1 position = ", s1->position);

        qlexengine::Application* a = new qlexengine::Application(); */

    qlexengine::Application* a = new qlexengine::Application();
    std::shared_ptr<qlexengine::Square> s1 = std::make_shared<qlexengine::Square>(50, qlexengine::maths::Vec3<float>(400, 400, 100), 1.0);
    std::shared_ptr<qlexengine::Square> s2 = std::make_shared<qlexengine::Square>(50, qlexengine::maths::Vec3<float>(0, 400, 100), qlexengine::maths::Vec3<float>(50, 0, 0), 1.0);

    a->addShape(s1);
    a->addShape(s2);

    a->start(0.016f);

    InitWindow(800, 600, "Hello Raylib");
    SetTargetFPS(30);

    while (!WindowShouldClose())
    {
        float deltaTime = GetFrameTime() / 4;


        a->start(deltaTime);

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("SEPT heures cumulés pour afficher ça!", 200, 200, 20, BLACK);
        qlexengine::Renderer::drawShapes<qlexengine::Shape>(a->getShapes());
        EndDrawing();
    }

    CloseWindow();
    return 0;
}