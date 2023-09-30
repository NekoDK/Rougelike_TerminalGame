#include "proj/systems/obstacles_control_system.h"

#include "lib/ecs/entity_manager.h"
#include "proj/components/coin_component.h"
#include "proj/components/collider_component.h"
#include "proj/components/enemy_component.h"
#include "proj/components/food_component.h"
#include "proj/components/movement_component.h"
#include "proj/components/obstacle_component.h"
#include "proj/components/player_control_component.h"
#include "proj/components/precollider_component.h"
#include "proj/components/statistic_component.h"
#include "proj/components/transform_component.h"
#include "proj/components/wall_component.h"

/**
 * Пример использования компонента как тэга - ObstacleComponent
 * позволяет отфильтровать сущности по факту наличия возможности столкновения
 */
void ObstaclesSystem::OnUpdate() {
  for (auto& entity1 : GetEntityManager()) {
    for (auto& entity2 : GetEntityManager()) {
      if (entity2.Contains<PlayerControlComponent>()) {
        if (entity1.Contains<CoinComponent>() && entity1.Contains<ColliderComponent>()) {
          auto cc = entity1.Get<ColliderComponent>();
          auto mc = entity1.Get<CoinComponent>();
          auto tc = entity1.Get<TransformComponent>();
          mc->multi_ = 0;
          for (const auto& collision : cc->GetCollisions()) {
            if (collision->Contains<PlayerControlComponent>()) {
              mc->multi_ = 1;
              tc->pos_.x = -1;
              tc->pos_.y = -1;
            }
          }
        }
      }
    }
  }

  for (auto& entity1 : GetEntityManager()) {
    for (auto& entity2 : GetEntityManager()) {
      if (entity2.Contains<PlayerControlComponent>()) {
        auto sc = entity2.Get<StatisticComponent>();
        if (entity1.Contains<FoodComponent>() && entity1.Contains<ColliderComponent>()) {
          auto cc = entity1.Get<ColliderComponent>();
          auto fc = entity1.Get<FoodComponent>();
          auto tc = entity1.Get<TransformComponent>();
          fc->multi_ = 0;
          for (const auto& collision : cc->GetCollisions()) {
            if (collision->Contains<PlayerControlComponent>()) {
              fc->multi_ = 1;
              sc->food_ += fc->cost_ * fc->multi_;
              tc->pos_.x = -1;
              tc->pos_.y = -1;
            }
          }
        }
      }
    }
  }

  for (auto& entity1 : GetEntityManager()) {
    for (auto& entity2 : GetEntityManager()) {
      if (entity1.Contains<MovementComponent>() && entity1.Contains<PlayerControlComponent>()) {
        auto mc = entity1.Get<MovementComponent>();
        if (entity2.Contains<WallComponent>() && entity2.Contains<PreColliderComponent>()) {
          auto pc = entity2.Get<PreColliderComponent>();
          for (const auto& collision : pc->GetCollisionsUp()) {
            if (collision->Contains<PlayerControlComponent>()) {
              mc->checkwalkUp_ = false;
            }
          }
          for (const auto& collision : pc->GetCollisionsDown()) {
            if (collision->Contains<PlayerControlComponent>()) {
              mc->checkwalkDown_ = false;
            }
          }
          for (const auto& collision : pc->GetCollisionsLeft()) {
            if (collision->Contains<PlayerControlComponent>()) {
              mc->checkwalkLeft_ = false;
            }
          }
          for (const auto& collision : pc->GetCollisionsRight()) {
            if (collision->Contains<PlayerControlComponent>()) {
              mc->checkwalkRight_ = false;
            }
          }
        }
      }
    }
  }

  for (auto& entity1 : GetEntityManager()) {
    for (auto& entity2 : GetEntityManager()) {
      if (entity1.Contains<MovementComponent>() && entity1.Contains<PlayerControlComponent>()) {
        auto mc = entity1.Get<MovementComponent>();
        auto st = entity1.Get<StatisticComponent>();
        if (entity2.Contains<EnemyComponent>() && entity2.Contains<PreColliderComponent>()) {
          auto pc = entity2.Get<PreColliderComponent>();
          auto ec = entity2.Get<EnemyComponent>();
          auto tc = entity2.Get<TransformComponent>();
          if (ec->health_ < 0) {
            tc->pos_.x = -1;
            tc->pos_.y = -1;
            ec->check_ = false;
          }
          for (const auto& collision : pc->GetCollisionsUp()) {
            if (collision->Contains<PlayerControlComponent>()) {
              mc->checkwalkUp_ = false;
              ec->health_ -= 2;
              st->health_ -= 2;
            }
          }
          for (const auto& collision : pc->GetCollisionsDown()) {
            if (collision->Contains<PlayerControlComponent>()) {
              mc->checkwalkDown_ = false;
              ec->health_ -= 2;
              st->health_ -= 2;
            }
          }
          for (const auto& collision : pc->GetCollisionsLeft()) {
            if (collision->Contains<PlayerControlComponent>()) {
              mc->checkwalkLeft_ = false;
              ec->health_ -= 2;
              st->health_ -= 2;
            }
          }
          for (const auto& collision : pc->GetCollisionsRight()) {
            if (collision->Contains<PlayerControlComponent>()) {
              mc->checkwalkRight_ = false;
              ec->health_ -= 2;
              st->health_ -= 2;
            }
          }
        }
      }
    }
  }

  for (auto& entity1 : GetEntityManager()) {
    for (auto& entity2 : GetEntityManager()) {
      if (entity1.Contains<MovementComponent>() && entity1.Contains<PlayerControlComponent>()) {
        auto mc = entity1.Get<MovementComponent>();
        if (entity2.Contains<WallComponent>() && entity2.Contains<PreColliderComponent>()) {
          auto pc = entity2.Get<PreColliderComponent>();
          for (const auto& collision : pc->GetCollisionsUp()) {
            if (collision->Contains<PlayerControlComponent>()) {
              mc->checkwalkUp_ = false;
            }
          }
          for (const auto& collision : pc->GetCollisionsDown()) {
            if (collision->Contains<PlayerControlComponent>()) {
              mc->checkwalkDown_ = false;
            }
          }
          for (const auto& collision : pc->GetCollisionsLeft()) {
            if (collision->Contains<PlayerControlComponent>()) {
              mc->checkwalkLeft_ = false;
            }
          }
          for (const auto& collision : pc->GetCollisionsRight()) {
            if (collision->Contains<PlayerControlComponent>()) {
              mc->checkwalkRight_ = false;
            }
          }
        }
      }
    }
  }
}

ObstaclesSystem::ObstaclesSystem(EntityManager* const entity_manager, SystemManager* const system_manager,
                                 float starting_point)
    : ISystem(entity_manager, system_manager) {}
