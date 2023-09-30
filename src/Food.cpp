#include <BearLibTerminal.h>
#include <Food.h>

int to_pos(float x);

void Food::Render() {
  terminal_color("red");
  terminal_put(to_pos(position_x_), to_pos(position_y_), icon_);
  terminal_color("white");
}

void Food::Update() {
  Render();
}

int Food::PosX() const {
  return position_x_;
}
int Food::PosY() const {
  return position_y_;
}

int Food::GetFoodCost() const {
  return food_cost_;
}
