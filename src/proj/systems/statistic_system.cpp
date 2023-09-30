#include "proj/systems/statistic_system.h"

#include <proj/components/coin_component.h>
#include <proj/components/statistic_component.h>

#include <iostream>

#include "lib/ecs/entity_manager.h"

static bool Filter(const Entity& entity1, const Entity& entity2) {
  return entity1.Contains<StatisticComponent>() && entity2.Contains<CoinComponent>();
}

void StatisticSystem::OnUpdateEntity(Entity* entity1, Entity* entity2) const {
  auto sc = entity1->Get<StatisticComponent>();
  auto cc = entity2->Get<CoinComponent>();

  sc->coins_ += cc->cost_ * cc->multi_;
  sc->food_ += cc->cost_ * cc->multi_;

  if (sc->food_ >= 80) {
    sc->foods_ = "Fooood!!!";
  }
  if (sc->food_ < 80) {
    sc->foods_ = "Food";
  }
  if (sc->food_ < 60) {
    sc->foods_ = "food";
  }
  if (sc->food_ < 40) {
    sc->foods_ = "foo";
  }
  if (sc->food_ < 30) {
    sc->foods_ = "fo";
  }
  if (sc->food_ < 20) {
    sc->foods_ = "f";
  }
  if (sc->food_ < 10) {
    sc->foods_ = "Death is near";
  }
  if (sc->food_ < 1) {
    sc->foods_ = "It is DEATH!!!";
  }
}

void StatisticSystem::OnUpdate() {
  for (auto& entity1 : GetEntityManager()) {
    for (auto& entity2 : GetEntityManager()) {
      if (Filter(entity1, entity2)) {
        OnUpdateEntity(&entity1, &entity2);
      }
    }
  }
}

StatisticSystem::StatisticSystem(EntityManager* const entity_manager, SystemManager* const system_manager)
    : ISystem(entity_manager, system_manager) {}
