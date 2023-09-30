#ifndef INCLUDE_PROJ_COMPONENTS_TRANSFORM_COMPONENT_H_
#define INCLUDE_PROJ_COMPONENTS_TRANSFORM_COMPONENT_H_
#include <lib/ecs/component.h>
#include <lib/math/vec2.h>

class TransformComponent : public IComponent {
 public:
  Vec2 pos_;

  explicit TransformComponent(const Vec2& pos) : pos_(pos) {}
};
#endif  // INCLUDE_PROJ_COMPONENTS_TRANSFORM_COMPONENT_H_
