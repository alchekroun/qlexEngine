#pragma once

#include <thread>
#include <vector>
#include <memory>

#include "physics/Shape.h"
#include "logger/logger.h"

namespace qlexengine
{

  class Application
  {
  public:
    bool initialize();

    bool start(float dt);

    void addShape(const std::shared_ptr<Shape> shape_) { _shapes.push_back(shape_); }
    bool removeShape(const std::shared_ptr<Shape> shape_);
    std::vector<std::shared_ptr<Shape>> getShapes() const { return _shapes; }

    void step(float dt);

    maths::Vec3<float> _gravity{0, -9.81f, 0};

  private:
    std::thread _mainThread;

    std::vector<std::shared_ptr<Shape>> _shapes;

    std::unique_ptr<logger> _log = std::make_unique<logger>("Application");
  };

} // qlexengine