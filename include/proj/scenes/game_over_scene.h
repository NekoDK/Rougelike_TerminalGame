#ifndef INCLUDE_PROJ_SCENES_GAME_OVER_SCENE_H_
#define INCLUDE_PROJ_SCENES_GAME_OVER_SCENE_H_

#include "lib/ecs/engine.h"
#include "lib/scenes/i_scene.h"
#include "proj/controls.h"

class GameOverScene : public IScene {
  const Controls& controls_;
  const Engine engine{};

 public:
  GameOverScene(Context* ctx, const Controls& controls);
  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
};

#endif  // INCLUDE_PROJ_SCENES_GAME_OVER_SCENE_H_
