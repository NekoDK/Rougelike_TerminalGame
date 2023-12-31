#ifndef INCLUDE_PROJ_SYSTEMS_COLLISION_SYSTEM_H_
#define INCLUDE_PROJ_SYSTEMS_COLLISION_SYSTEM_H_

#include <lib/ecs/system.h>
class CollisionSystem : public ISystem {
 public:
  CollisionSystem(EntityManager* entity_manager, SystemManager* system_manager);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_PROJ_SYSTEMS_COLLISION_SYSTEM_H_
