#pragma once

#include <thread>
#include <vector>
#include <memory>

#include "logger/logger.h"
#include "Engine.h"
#include "render/Renderer.h"

namespace qlexengine
{

  enum Application_STATE
  {
    DOWN,
    RUNNING,
  };

  class Application
  {
  public:
    bool initialize();
    bool start(const float &dt);
    bool stop();

    std::unique_ptr<Engine> _physicEngine = std::make_unique<Engine>();
    std::unique_ptr<Renderer> _renderer = std::make_unique<Renderer>();

  private:
    std::thread _mainThread;
    Application_STATE _state;
    inline static int _FPS = 60;
    inline static int _WINDOW_HEIGHT = 800;
    inline static int _WINDOW_WIDTH = 600;
    inline static std::string _WINDOW_HEADER_TEXT = "qlexEngine - Test Zone";
    std::unique_ptr<logger> _log = std::make_unique<logger>("Application");
  };

} // qlexengine