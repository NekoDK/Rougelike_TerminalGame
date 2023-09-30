#ifndef INCLUDE_PROJ_COMPONENTS_TEXTURE_COMPONENT_H_
#define INCLUDE_PROJ_COMPONENTS_TEXTURE_COMPONENT_H_
#include <lib/ecs/component.h>

class TextureComponent : public IComponent {
 public:
  char symbol_;

  explicit TextureComponent(char symbol) : symbol_(symbol) {}
};
#endif  // INCLUDE_PROJ_COMPONENTS_TEXTURE_COMPONENT_H_
