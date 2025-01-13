#include <iostream>

#include "logger/logger.h"
#include "engine/Application.h"

#include <raylib.h>

std::unique_ptr<qlexengine::logger> _log = std::make_unique<qlexengine::logger>("MAIN");

int main()
{
    qlexengine::Application *a = new qlexengine::Application();
    a->initialize();
    a->start(1.0);
    return 0;
}