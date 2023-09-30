#ifndef INCLUDE_PROJ_COMPONENTS_COIN_COMPONENT_H_
#define INCLUDE_PROJ_COMPONENTS_COIN_COMPONENT_H_

#include <lib/ecs/component.h>
class CoinComponent : public IComponent {
 public:
  int cost_;
  int multi_ = 0;

  explicit CoinComponent(int cost) : cost_(cost) {}
};

#endif  // INCLUDE_PROJ_COMPONENTS_COIN_COMPONENT_H_
