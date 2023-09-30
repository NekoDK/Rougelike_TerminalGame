//
// Created by AsTeFu on 16.08.2019.
//

#ifndef INCLUDE_PROJ_SYSTEMS_GAME_WIN_SYSTEM_H_
#define INCLUDE_PROJ_SYSTEMS_GAME_WIN_SYSTEM_H_

#include <lib/ecs/system.h>
#include <lib/scenes/context.h>

class GameWinSystem : public ISystem {
 private:
  Context* ctx_;

  void GameWin();

 protected:
  void OnUpdate() override;

 public:
  GameWinSystem(EntityManager* const entity_manager, SystemManager* const system_manager, Context* ctx)
      : ISystem(entity_manager, system_manager), ctx_(ctx) {}
};

#endif  // INCLUDE_PROJ_SYSTEMS_GAME_WIN_SYSTEM_H_
