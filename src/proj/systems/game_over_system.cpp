//
// Created by AsTeFu on 16.08.2019.
//

#include "proj/systems/game_over_system.h"

#include <lib/ecs/entity.h>
#include <lib/ecs/entity_manager.h>
#include <proj/components/collider_component.h>
#include <proj/components/obstacle_component.h>
#include <proj/components/player_control_component.h>
#include <proj/components/statistic_component.h>

static bool Filter(const Entity& entity) {
  return entity.Contains<StatisticComponent>() && entity.Contains<PlayerControlComponent>();
}

static bool IsGameOver(const Entity& entity) {
  auto sc = entity.Get<StatisticComponent>();
  if (sc->health_ < 0 || sc->food_ < 0) {
    return true;
  }

  return false;
}

void GameOverSystem::GameOver() {
  ctx_->scene_ = "game_over";
}

void GameOverSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (Filter(entity) && IsGameOver(entity)) {
      GameOver();
    }
  }
}
