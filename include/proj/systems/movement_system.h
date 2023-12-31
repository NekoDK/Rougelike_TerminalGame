#ifndef INCLUDE_PROJ_SYSTEMS_MOVEMENT_SYSTEM_H_
#define INCLUDE_PROJ_SYSTEMS_MOVEMENT_SYSTEM_H_

#include <lib/ecs/system.h>

class MovementSystem : public ISystem {
 public:
  MovementSystem(EntityManager* entity_manager, SystemManager* system_manager);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_PROJ_SYSTEMS_MOVEMENT_SYSTEM_H_
