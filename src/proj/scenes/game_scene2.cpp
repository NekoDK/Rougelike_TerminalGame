#include "proj/scenes/game_scene2.h"

#include <proj/components/collider_component.h>
#include <proj/components/food_component.h>
#include <proj/components/gravity_component.h>
#include <proj/components/jump_component.h>
#include <proj/components/player_control_component.h>
#include <proj/systems/ai_system.h>
#include <proj/systems/collision_system.h>
#include <proj/systems/game_over_system.h>
#include <proj/systems/gravity_system.h>
#include <proj/systems/jump_control_system.h>
#include <proj/systems/precollision_system.h>
#include <proj/systems/statistic_system.h>

#include "lib/math/vec2.h"
#include "proj/components/coin_component.h"
#include "proj/components/enemy_component.h"
#include "proj/components/id_component.h"
#include "proj/components/movement_component.h"
#include "proj/components/obstacle_component.h"
#include "proj/components/precollider_component.h"
#include "proj/components/statistic_component.h"
#include "proj/components/texture_component.h"
#include "proj/components/transform_component.h"
#include "proj/components/wall_component.h"
#include "proj/systems/delete_system.h"
#include "proj/systems/movement_system.h"
#include "proj/systems/obstacles_control_system.h"
#include "proj/systems/rendering_system.h"
/**
 * На каждую игровую сцену приходится свой набор сущностей и систем
 * Так, например, здесь у нас есть сущности игрока, кактусов и земли,
 * у каждой сущнности есть свой набор компонентов
 * (обратите внимание, что и аргументы у каждого соответствующие)
 *
 * После инициализации всех сущностей (а они хранятся в движке ECS),
 * происходит инициализация всех необходимых систем. Как и сущности,
 * они хранятся в движке ECS. Благодаря этому, при вызове OnUpdate()
 * у сцены достаточно вызвать только обновление движка ECS
 *
 * После того, как сцена заканчивает свою работу, содержимое движка ECS
 * очищается, чтобы другая сцена могла заполнить его своими компонентам
 * и системами
 */
void GameScene2::OnCreate() {
  {
    auto player = engine.GetEntityManager()->CreateEntity();
    player->Add<TransformComponent>(Vec2(1, ground_y_ - 1));
    player->Add<TextureComponent>('@');
    player->Add<MovementComponent>(ZeroVec2, RightVec2);
    player->Add<JumpComponent>(2, gravity_ * 5, ground_y_);
    player->Add<PlayerControlComponent>(TK_UP, TK_DOWN, TK_RIGHT, TK_LEFT);
    player->Add<StatisticComponent>(0, 100, 200);
    player->Add<ColliderComponent>(OnesVec2, ZeroVec2);
    player->Add<ObstacleComponent>();
    player->Add<PreColliderComponent>(OnesVec2, ZeroVec2);
  }

  for (int i = 10; i < 40; i++) {
    for (int j = 10; j < 16; j++) {
      if (i % 2 == 0) {
        auto coin = engine.GetEntityManager()->CreateEntity();
        coin->Add<TransformComponent>(Vec2(i, j));
        coin->Add<TextureComponent>('$');
        coin->Add<CoinComponent>(10);
        coin->Add<ObstacleComponent>();
        coin->Add<ColliderComponent>(OnesVec2, ZeroVec2);
      }
      if (i % 2 == 1) {
        auto food = engine.GetEntityManager()->CreateEntity();
        food->Add<TransformComponent>(Vec2(i, j));
        food->Add<TextureComponent>('%');
        food->Add<FoodComponent>(10);
        food->Add<ObstacleComponent>();
        food->Add<ColliderComponent>(OnesVec2, ZeroVec2);
      }
    }
  }

  auto sys = engine.GetSystemManager();
  sys->AddSystem<RenderingSystem>();
  sys->AddSystem<MovementSystem>();
  sys->AddSystem<ObstaclesSystem>(width_);
  sys->AddSystem<JumpControlSystem>(controls);
  sys->AddSystem<GravitySystem>();
  sys->AddSystem<CollisionSystem>();
  sys->AddSystem<GameOverSystem>(ctx_);
  sys->AddSystem<StatisticSystem>();
  sys->AddSystem<PrecollisionSystem>();
  sys->AddSystem<AiSystem>();
}
void GameScene2::OnRender() {
  engine.OnUpdate();
}
void GameScene2::OnExit() {
  engine.GetEntityManager()->DeleteAll();
  engine.GetSystemManager()->DeleteAll();
}
GameScene2::GameScene2(Context* const ctx, const Controls& controls) : IScene(ctx), controls(controls) {}
