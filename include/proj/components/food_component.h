#ifndef INCLUDE_PROJ_COMPONENTS_FOOD_COMPONENT_H_
#define INCLUDE_PROJ_COMPONENTS_FOOD_COMPONENT_H_

#include <lib/ecs/component.h>
class FoodComponent : public IComponent {
 public:
  int cost_;
  int multi_ = 0;

  explicit FoodComponent(int cost) : cost_(cost) {}
};

#endif  // INCLUDE_PROJ_COMPONENTS_FOOD_COMPONENT_H_
