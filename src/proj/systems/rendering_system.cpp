#include "proj/systems/rendering_system.h"

#include <BearLibTerminal.h>

#include "lib/ecs/entity_manager.h"
#include "proj/components/coin_component.h"
#include "proj/components/statistic_component.h"
#include "proj/components/texture_component.h"
#include "proj/components/transform_component.h"
#include "proj/math-utils.h"

void RenderingSystem::OnUpdate() {
  for (auto& e : GetEntityManager()) {
    if (e.Contains<TransformComponent>() && e.Contains<TextureComponent>()) {
      auto texture = e.Get<TextureComponent>();
      auto transform = e.Get<TransformComponent>();

      terminal_put(ToPos(transform->pos_.x), ToPos(transform->pos_.y), texture->symbol_);
    }
    if (e.Contains<StatisticComponent>()) {
      auto st = e.Get<StatisticComponent>();
      terminal_printf(2, 2, "Coins %d", st->coins_);
      terminal_printf(2, 3, "%s", st->foods_.c_str());
      terminal_printf(2, 4, "Health %d", st->health_);
      terminal_printf(2, 5, "Steps %d", st->steps_);
    }
  }
}
void RenderingSystem::OnPreUpdate() {
  terminal_clear();
}
void RenderingSystem::OnPostUpdate() {
  terminal_refresh();
}
RenderingSystem::RenderingSystem(EntityManager* const entity_manager, SystemManager* const system_manager)
    : ISystem(entity_manager, system_manager) {}
