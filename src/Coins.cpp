#include <BearLibTerminal.h>
#include <Coins.h>

int to_pos(float x);

void Coins::Render() {
  terminal_color("green");
  terminal_put(to_pos(position_x_), to_pos(position_y_), icon_);
  terminal_color("white");
}

void Coins::Update() {
  Render();
}

int Coins::PosX() const {
  return position_x_;
}
int Coins::PosY() const {
  return position_y_;
}

int Coins::GetCoinsCost() const {
  return coins_cost_;
}
