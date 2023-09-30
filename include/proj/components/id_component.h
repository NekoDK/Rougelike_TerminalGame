#ifndef INCLUDE_PROJ_COMPONENTS_ID_COMPONENT_H_
#define INCLUDE_PROJ_COMPONENTS_ID_COMPONENT_H_

#include <lib/ecs/component.h>
class IdComponent : public IComponent {
 public:
  int id_;

  explicit IdComponent() {}
};

#endif  // INCLUDE_PROJ_COMPONENTS_ID_COMPONENT_H_
