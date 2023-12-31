#ifndef INCLUDE_PROJ_COMPONENTS_PLAYER_CONTROL_COMPONENT_H_
#define INCLUDE_PROJ_COMPONENTS_PLAYER_CONTROL_COMPONENT_H_

#include <lib/ecs/component.h>

class PlayerControlComponent : public IComponent {
 public:
  int up_button_;
  int down_button_;
  int right_button_;
  int left_button_;

  explicit PlayerControlComponent(int up_button, int down_button, int right_button, int left_button)
      : up_button_(up_button), down_button_(down_button), right_button_(right_button), left_button_(left_button) {}
};

#endif  // INCLUDE_PROJ_COMPONENTS_PLAYER_CONTROL_COMPONENT_H_
