#ifndef INCLUDE_PROJ_COMPONENTS_PRECOLLIDER_COMPONENT_H_
#define INCLUDE_PROJ_COMPONENTS_PRECOLLIDER_COMPONENT_H_

#include <lib/ecs/component.h>
#include <lib/math/vec2.h>

#include <set>

class Entity;

/**
 * Данный компонент - идеальный пример компонента с состоянием
 * Во множестве собирается информация о том, с кем произошло столкновение,
 * которое затем анализируется системой коллизий
 */
class PreColliderComponent : public IComponent {
  // std::set<Entity*> collisions_{};
  std::set<Entity*> collisions_up_{};
  std::set<Entity*> collisions_down_{};
  std::set<Entity*> collisions_right_{};
  std::set<Entity*> collisions_left_{};

 public:
  Vec2 size_;
  Vec2 offset_;

  explicit PreColliderComponent(const Vec2& size, const Vec2& offset = ZeroVec2) : size_(size), offset_(offset) {}

  const std::set<Entity*>& GetCollisionsUp() const {
    return collisions_up_;
  }

  const std::set<Entity*>& GetCollisionsDown() const {
    return collisions_down_;
  }

  const std::set<Entity*>& GetCollisionsLeft() const {
    return collisions_left_;
  }

  const std::set<Entity*>& GetCollisionsRight() const {
    return collisions_right_;
  }

  // bool AnyCollisions() const {
  //   return !collisions_.empty();
  // }

  void CollideUp(Entity* entity) {
    collisions_up_.insert(entity);
  }

  void CollideDown(Entity* entity) {
    collisions_down_.insert(entity);
  }

  void CollideLeft(Entity* entity) {
    collisions_left_.insert(entity);
  }

  void CollideRight(Entity* entity) {
    collisions_right_.insert(entity);
  }

  void Clear() {
    collisions_up_.clear();
    collisions_down_.clear();
    collisions_left_.clear();
    collisions_right_.clear();
  }
};

#endif  // INCLUDE_PROJ_COMPONENTS_PRECOLLIDER_COMPONENT_H_
