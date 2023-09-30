#ifndef INCLUDE_PROJ_SCENES_TITLE_SCENE_H_
#define INCLUDE_PROJ_SCENES_TITLE_SCENE_H_

#include "lib/scenes/i_scene.h"
#include "proj/controls.h"

class TitleScene : public IScene {
  const Controls& controls_;

 public:
  TitleScene(Context* ctx, const Controls& controls);

  void OnCreate() override;
  void OnRender() override;
  void OnExit() override;
};

#endif  // INCLUDE_PROJ_SCENES_TITLE_SCENE_H_
