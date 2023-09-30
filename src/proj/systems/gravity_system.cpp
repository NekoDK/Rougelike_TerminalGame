#include "proj/systems/gravity_system.h"

#include <lib/ecs/entity.h>
#include <lib/ecs/entity_manager.h>
#include <proj/components/gravity_component.h>
#include <proj/components/transform_component.h>

static bool Filter(const Entity& entity) {
  return entity.Contains<GravityComponent>() && entity.Contains<TransformComponent>();
}
void GravitySystem::OnUpdate() {
  for (auto& entity : GetEntityManager()) {
    if (Filter(entity)) {
      auto tc = entity.Get<TransformComponent>();
      auto gc = entity.Get<GravityComponent>();

      if (tc->pos_.y > gc->ground_y_ - 1) {
        tc->pos_.y = gc->ground_y_ - 1;
      }
      tc->pos_.y += gc->gravity_;  // TODO: multiply by delta-time
    }
  }
}
