#ifndef INCLUDE_PROJ_SYSTEMS_STATISTIC_SYSTEM_H_
#define INCLUDE_PROJ_SYSTEMS_STATISTIC_SYSTEM_H_

#include <lib/ecs/system.h>

class Entity;  // forward declaration because we include this class in the cpp file

class StatisticSystem : public ISystem {
  void OnUpdateEntity(Entity* entity1, Entity* entity2) const;

 protected:
  void OnUpdate() override;

 public:
  StatisticSystem(EntityManager* entity_manager, SystemManager* system_manager);
};

#endif  // INCLUDE_PROJ_SYSTEMS_STATISTIC_SYSTEM_H_
