#pragma once

#include <thread>
#include <vector>
#include <memory>

#include "logger/logger.h"
#include "Engine.h"
#include "render/Renderer.h"

namespace qlexengine
{

  enum Application_STATE {
    DOWN,
    RUNNING,
  };

  class Application
  {
  public:
    bool initialize();

    bool start(const float& dt);

    std::unique_ptr<Engine> _physicEngine = std::make_unique<Engine>();
    std::unique_ptr<Renderer> _renderer = std::make_unique<Renderer>();

  private:
    std::thread _mainThread;
    Application_STATE _state;
    std::unique_ptr<logger> _log = std::make_unique<logger>("Application");
  };

} // qlexengine