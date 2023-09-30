#ifndef INCLUDE_PROJ_COMPONENTS_ZOMBY_COMPONENT_H_
#define INCLUDE_PROJ_COMPONENTS_ZOMBY_COMPONENT_H_

#include <lib/ecs/component.h>

/**
 * Иногда компоненты могут не иметь полей в принципе.
 * В таком случае такие компоненты выступают как тэги, которые
 * используются системами для определения типа сущности
 */
class ZombyComponent : public IComponent {
  // Nothing to do, because it's a tag for systems
};

#endif  // INCLUDE_PROJ_COMPONENTS_ZOMBY_COMPONENT_H_
