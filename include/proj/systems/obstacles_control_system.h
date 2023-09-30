#ifndef INCLUDE_PROJ_SYSTEMS_OBSTACLES_CONTROL_SYSTEM_H_
#define INCLUDE_PROJ_SYSTEMS_OBSTACLES_CONTROL_SYSTEM_H_

#include <lib/ecs/engine.h>
#include <lib/ecs/entity.h>
#include <lib/ecs/system.h>

class ObstaclesSystem : public ISystem {
  const Engine engine{};

 public:
  ObstaclesSystem(EntityManager* entity_manager, SystemManager* system_manager, float starting_point);

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_PROJ_SYSTEMS_OBSTACLES_CONTROL_SYSTEM_H_
