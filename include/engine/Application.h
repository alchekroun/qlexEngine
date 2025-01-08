#pragma once

#include <thread>
#include <vector>
#include <memory>

#include "physics/Shape2D.h"
#include "logger/logger.h"

namespace qlexengine
{

  class Application
  {
  public:
    bool initialize();

    bool start(float dt);

    void addShape2D(const std::shared_ptr<Shape2D> shape_) { _shapes.push_back(shape_); }
    bool removeShape2D(const std::shared_ptr<Shape2D> shape_);
    std::vector<std::shared_ptr<Shape2D>> getShapes() const { return _shapes; }

    void step(float dt);

    maths::Vec2<float> _gravity2D{0, -9.81f};

  private:
    std::thread _mainThread;

    std::vector<std::shared_ptr<Shape2D>> _shapes;

    std::unique_ptr<logger> _log = std::make_unique<logger>("Application");
  };

} // qlexengine