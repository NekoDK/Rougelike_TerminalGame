#ifndef INCLUDE_PROJ_COMPONENTS_ENEMY_COMPONENT_H_
#define INCLUDE_PROJ_COMPONENTS_ENEMY_COMPONENT_H_

#include <lib/ecs/component.h>
class EnemyComponent : public IComponent {
 public:
  bool check_ = true;
  int id_;
  int health_;

  explicit EnemyComponent(int health, int id) : health_(health), id_(id) {}
};

#endif  // INCLUDE_PROJ_COMPONENTS_ENEMY_COMPONENT_H_
