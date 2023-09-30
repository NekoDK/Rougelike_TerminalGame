#ifndef INCLUDE_PROJ_COMPONENTS_DATA_COMPONENT_H_
#define INCLUDE_PROJ_COMPONENTS_DATA_COMPONENT_H_
#include <lib/ecs/component.h>
#include <lib/math/vec2.h>

#include <vector>

class DataComponent : public IComponent {
 public:
  std::vector<Vec2> walls{};

  explicit DataComponent() {}

  void AddWall(float x, float y) {
    walls.push_back(Vec2(x, y));
  }
};
#endif  // INCLUDE_PROJ_COMPONENTS_DATA_COMPONENT_H_
