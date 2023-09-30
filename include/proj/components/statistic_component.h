#ifndef INCLUDE_PROJ_COMPONENTS_STATISTIC_COMPONENT_H_
#define INCLUDE_PROJ_COMPONENTS_STATISTIC_COMPONENT_H_
#include <lib/ecs/component.h>

#include <string>
class StatisticComponent : public IComponent {
 public:
  int coins_;
  int food_;
  int health_;
  int steps_ = 0;

  std::string healths_;
  std::string foods_;

  explicit StatisticComponent(int coins, int food, int health) : coins_(coins), food_(food), health_(health) {}
  explicit StatisticComponent() {}
};

#endif  // INCLUDE_PROJ_COMPONENTS_STATISTIC_COMPONENT_H_
