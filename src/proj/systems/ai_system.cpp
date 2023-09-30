#include "proj/systems/ai_system.h"

#include <lib/ecs/entity.h>
#include <lib/ecs/entity_manager.h>
#include <proj/components/enemy_component.h>
#include <proj/components/movement_component.h>
#include <proj/components/player_control_component.h>
#include <proj/components/transform_component.h>

#include "proj/components/statistic_component.h"

static bool Filter(const Entity& entity) {
  return entity.Contains<EnemyComponent>() && entity.Contains<MovementComponent>();
}

void AiSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    for (auto& entity2 : GetEntityManager()) {
      if (entity2.Contains<PlayerControlComponent>()) {
        auto sc = entity2.Get<StatisticComponent>();
        if (Filter(entity)) {
          auto ec = entity.Get<EnemyComponent>();
          auto tc = entity.Get<TransformComponent>();
          auto mc = entity.Get<MovementComponent>();
          if (ec->check_ && ec->id_ == 1) {
            mc->direction_ = ZeroVec2;
            mc->speed_ = ZeroVec2;
            if (tc->pos_.x < 10 || tc->pos_.x > 30 || tc->pos_.y < 10 || tc->pos_.y > 17) {
              tc->pos_.x = 20;
              tc->pos_.y = 13;
            }
            if (sc->food_ % 5 == 0) {
              mc->direction_ = UpVec2;
              mc->speed_ = Vec2(0.0f, 0.2f);
            }
            if (sc->steps_ % 3 == 2) {
              mc->direction_ = RightVec2;
              mc->speed_ = Vec2(0.2f, 0.05f);
            }
            if (sc->steps_ % 5 == 3) {
              mc->direction_ = DownVec2;
              mc->speed_ = Vec2(0.0f, 0.2f);
            }
            if (sc->steps_ % 3 == 1) {
              mc->direction_ = LeftVec2;
              mc->speed_ = Vec2(0.2f, 0.05f);
            }
          }
          if (ec->check_ && ec->id_ == 2) {
            mc->direction_ = ZeroVec2;
            mc->speed_ = ZeroVec2;
            if (tc->pos_.x < 30 || tc->pos_.x > 41 || tc->pos_.y < 13 || tc->pos_.y > 16) {
              tc->pos_.x = 37;
              tc->pos_.y = 13;
            }
            if (sc->food_ % 5 == 0) {
              mc->direction_ = UpVec2;
              mc->speed_ = Vec2(0.0f, 0.25f);
            }
            if (sc->steps_ % 3 == 2) {
              mc->direction_ = RightVec2;
              mc->speed_ = Vec2(0.25f, 0.05f);
            }
            if (sc->steps_ % 5 == 3) {
              mc->direction_ = DownVec2;
              mc->speed_ = Vec2(0.0f, 0.25f);
            }
            if (sc->steps_ % 3 == 1) {
              mc->direction_ = LeftVec2;
              mc->speed_ = Vec2(0.25f, 0.05f);
            }
          }
        }
      }
    }
  }
}
