#ifndef INCLUDE_OBSTACLE_H_
#define INCLUDE_OBSTACLE_H_
#include <vector>

class Obstacle {
  char icon_ = '#';

 public:
  float position_x_;
  float position_y_;
  std::vector<Obstacle> obstacles_{};

  Obstacle(float position_x, float position_y) : position_x_(position_x), position_y_(position_y) {}
  Obstacle() {}
  void Update();

  int PosX() const;
  int PosY() const;
};

#endif  // INCLUDE_OBSTACLE_H_
