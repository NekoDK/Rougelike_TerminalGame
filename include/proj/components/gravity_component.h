#ifndef INCLUDE_PROJ_COMPONENTS_GRAVITY_COMPONENT_H_
#define INCLUDE_PROJ_COMPONENTS_GRAVITY_COMPONENT_H_

#include <lib/ecs/component.h>
class GravityComponent : public IComponent {
 public:
  float gravity_;
  float ground_y_;

  GravityComponent(float gravity, float ground_y) : gravity_(gravity), ground_y_(ground_y) {}
};

#endif  // INCLUDE_PROJ_COMPONENTS_GRAVITY_COMPONENT_H_
