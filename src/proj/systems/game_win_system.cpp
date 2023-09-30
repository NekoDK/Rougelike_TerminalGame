//
// Created by AsTeFu on 16.08.2019.
//

#include "proj/systems/game_win_system.h"

#include <lib/ecs/entity.h>
#include <lib/ecs/entity_manager.h>
#include <proj/components/exit_component.h>
#include <proj/components/movement_component.h>
#include <proj/components/obstacle_component.h>
#include <proj/components/player_control_component.h>
#include <proj/components/precollider_component.h>

void GameWinSystem::GameWin() {
  ctx_->scene_ = "game2";
}

void GameWinSystem::OnUpdate() {
  for (auto& entity1 : GetEntityManager()) {
    for (auto& entity2 : GetEntityManager()) {
      if (entity1.Contains<MovementComponent>() && entity1.Contains<PlayerControlComponent>()) {
        auto mc = entity1.Get<MovementComponent>();
        if (entity2.Contains<EXITComponent>() && entity2.Contains<PreColliderComponent>()) {
          auto pc = entity2.Get<PreColliderComponent>();
          for (const auto& collision : pc->GetCollisionsUp()) {
            if (collision->Contains<PlayerControlComponent>()) {
              GameWin();
            }
          }
          for (const auto& collision : pc->GetCollisionsDown()) {
            if (collision->Contains<PlayerControlComponent>()) {
              GameWin();
            }
          }
          for (const auto& collision : pc->GetCollisionsLeft()) {
            if (collision->Contains<PlayerControlComponent>()) {
              GameWin();
            }
          }
          for (const auto& collision : pc->GetCollisionsRight()) {
            if (collision->Contains<PlayerControlComponent>()) {
              GameWin();
            }
          }
        }
      }
    }
  }
}
