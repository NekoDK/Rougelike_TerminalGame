#ifndef INCLUDE_PROJ_SYSTEMS_AI_SYSTEM_H_
#define INCLUDE_PROJ_SYSTEMS_AI_SYSTEM_H_

#include <lib/ecs/system.h>

class AiSystem : public ISystem {
 public:
  AiSystem(EntityManager* const entity_manager, SystemManager* const system_manager)
      : ISystem(entity_manager, system_manager) {}

 protected:
  void OnUpdate() override;
};

#endif  // INCLUDE_PROJ_SYSTEMS_AI_SYSTEM_H_
