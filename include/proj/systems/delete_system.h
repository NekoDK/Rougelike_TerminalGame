#ifndef INCLUDE_PROJ_SYSTEMS_DELETE_SYSTEM_H_
#define INCLUDE_PROJ_SYSTEMS_DELETE_SYSTEM_H_

#include <lib/ecs/engine.h>
#include <lib/ecs/system.h>

class DeleteSystem : public ISystem {
  const Engine engine{};

 public:
  DeleteSystem(EntityManager* const entity_manager, SystemManager* const system_manager)
      : ISystem(entity_manager, system_manager) {}

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_PROJ_SYSTEMS_DELETE_SYSTEM_H_
