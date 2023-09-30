#ifndef INCLUDE_PROJ_SCENES_GAME_SCENE2_H_
#define INCLUDE_PROJ_SCENES_GAME_SCENE2_H_

#include <lib/ecs/engine.h>
#include <lib/scenes/i_scene.h>
#include <proj/controls.h>

class GameScene2 : public IScene {
  const int width_ = 80;
  const int ground_y_ = 15;
  const float gravity_ = 0.2;
  const Engine engine{};
  const Controls& controls;

 public:
  GameScene2(Context* const ctx, const Controls& controls);

  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
};

#endif  // INCLUDE_PROJ_SCENES_GAME_SCENE2_H_
