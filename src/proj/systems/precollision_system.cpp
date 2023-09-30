#include "proj/systems/precollision_system.h"

#include <lib/ecs/entity.h>
#include <lib/ecs/entity_manager.h>
#include <proj/components/precollider_component.h>
#include <proj/components/transform_component.h>
#include <proj/math-utils.h>

static bool Filter(const Entity& entity) {
  return entity.Contains<PreColliderComponent>() && entity.Contains<TransformComponent>();
}

static void Collide(Entity* entity_1, Entity* entity_2) {
  if (entity_1->GetId() == entity_2->GetId()) {
    return;
  }

  auto cc2 = entity_2->Get<PreColliderComponent>();

  auto tc1 = entity_1->Get<TransformComponent>();
  auto tc2 = entity_2->Get<TransformComponent>();

  if (ToPos(tc1->pos_.x) + 1 == ToPos(tc2->pos_.x) && ToPos(tc1->pos_.y) == ToPos(tc2->pos_.y)) {  // left
    cc2->CollideRight(entity_1);
  }
  if (ToPos(tc1->pos_.x) - 1 == ToPos(tc2->pos_.x) && ToPos(tc1->pos_.y) == ToPos(tc2->pos_.y)) {  // right
    cc2->CollideLeft(entity_1);
  }
  if (ToPos(tc1->pos_.x) == ToPos(tc2->pos_.x) && ToPos(tc1->pos_.y) + 1 == ToPos(tc2->pos_.y)) {  // down
    cc2->CollideDown(entity_1);
  }
  if (ToPos(tc1->pos_.x) == ToPos(tc2->pos_.x) && ToPos(tc1->pos_.y) - 1 == ToPos(tc2->pos_.y)) {  // up
    cc2->CollideUp(entity_1);
  }
}

PrecollisionSystem::PrecollisionSystem(EntityManager* entity_manager, SystemManager* system_manager)
    : ISystem(entity_manager, system_manager) {}

void PrecollisionSystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (entity.Contains<PreColliderComponent>()) {
      entity.Get<PreColliderComponent>()->Clear();
    }
  }

  for (auto& entity_1 : GetEntityManager()) {
    if (Filter(entity_1)) {
      for (auto& entity_2 : GetEntityManager()) {
        if (Filter(entity_2)) {
          Collide(&entity_1, &entity_2);
        }
      }
    }
  }
}
