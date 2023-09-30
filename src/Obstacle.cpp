#include <BearLibTerminal.h>
#include <Obstacle.h>

#include <vector>

int to_pos(float x);

void Obstacle::Update() {
  terminal_put(to_pos(position_x_), to_pos(position_y_), icon_);
}

int Obstacle::PosX() const {
  return position_x_;
}
int Obstacle::PosY() const {
  return position_y_;
}
