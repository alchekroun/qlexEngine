#include "engine/Application.h"

namespace qlexengine
{

    bool Application::initialize()
    {
        _physicEngine->initialize();
        _renderer->initialize();
        _state = RUNNING;
        return true;
    }

    bool Application::start(const float& dt)
    {
        _physicEngine->start();
        _renderer->start();
        return true;
    }

} // qlexengine