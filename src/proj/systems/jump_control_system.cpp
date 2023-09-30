#include "proj/systems/jump_control_system.h"

#include <proj/components/jump_component.h>
#include <proj/components/movement_component.h>
#include <proj/components/player_control_component.h>
#include <proj/components/statistic_component.h>
#include <proj/components/transform_component.h>

#include <iostream>

#include "lib/ecs/entity_manager.h"

static bool Filter(const Entity& entity) {
  return entity.Contains<MovementComponent>() && entity.Contains<JumpComponent>() &&
         entity.Contains<PlayerControlComponent>() && entity.Contains<TransformComponent>();
}

void JumpControlSystem::OnUpdateEntity(Entity* entity) const {
  auto mc = entity->Get<MovementComponent>();
  auto pcc = entity->Get<PlayerControlComponent>();
  auto jc = entity->Get<JumpComponent>();
  auto tc = entity->Get<TransformComponent>();
  auto st = entity->Get<StatisticComponent>();

  if (!controls_.IsPressed(pcc->up_button_)) {
    mc->speed_.y = 0;
  }
  if (!controls_.IsPressed(pcc->down_button_)) {
    mc->speed_.y = 0;
  }
  if (!controls_.IsPressed(pcc->right_button_)) {
    mc->speed_.x = 0;
  }
  if (!controls_.IsPressed(pcc->left_button_)) {
    mc->speed_.x = 0;
  }
  if (controls_.IsPressed(pcc->up_button_) && mc->checkwalkUp_) {
    mc->direction_ = UpVec2;
    mc->speed_.y = jc->max_speed_y_;
    st->steps_++;
    st->food_--;
    mc->checkwalkDown_ = true;
    mc->checkwalkRight_ = true;
    mc->checkwalkLeft_ = true;
  }
  if (controls_.IsPressed(pcc->down_button_) && mc->checkwalkDown_) {  //
    mc->direction_ = DownVec2;
    mc->speed_.y = jc->max_speed_y_;
    st->steps_++;
    st->food_--;
    mc->checkwalkUp_ = true;
    mc->checkwalkRight_ = true;
    mc->checkwalkLeft_ = true;
  }
  if (controls_.IsPressed(pcc->right_button_) && mc->checkwalkRight_) {  //
    mc->direction_ = RightVec2;
    mc->speed_.x = jc->max_speed_y_;
    st->steps_++;
    st->food_--;
    mc->checkwalkUp_ = true;
    mc->checkwalkDown_ = true;
    mc->checkwalkLeft_ = true;
  }
  if (controls_.IsPressed(pcc->left_button_) && mc->checkwalkLeft_) {  //
    mc->direction_ = LeftVec2;
    mc->speed_.x = jc->max_speed_y_;
    st->steps_++;
    st->food_--;
    mc->checkwalkUp_ = true;
    mc->checkwalkDown_ = true;
    mc->checkwalkRight_ = true;
  }
}

void JumpControlSystem::OnUpdate() {
  // TODO: it's slow as O(n) because to find an entity we should iterate over ALL entities.
  // But we know there is only one player to control, so may be some tag could be useful.
  for (auto& entity : GetEntityManager()) {
    if (Filter(entity)) {
      OnUpdateEntity(&entity);
    }
  }
}
JumpControlSystem::JumpControlSystem(EntityManager* const entity_manager, SystemManager* const system_manager,
                                     const Controls& controls)
    : ISystem(entity_manager, system_manager), controls_(controls) {}
