#include <BearLibTerminal.h>
#include <Player.h>

int to_pos(float x);

void Player::Move() {
  if (controls.IsUp() && walk_status_up_) {
    position_y_ -= speed_;
    steps_++;
    hunger_--;
  }
  if (controls.IsDown() && walk_status_down_) {
    position_y_ += speed_;
    steps_++;
    hunger_--;
  }
  if (controls.IsLeft() && walk_status_left_) {
    position_x_ -= speed_;
    steps_++;
    hunger_--;
  }
  if (controls.IsRight() && walk_status_right_) {
    position_x_ += speed_;
    steps_++;
    hunger_--;
  }
}

void Player::Render() {
  terminal_put(to_pos(position_x_), to_pos(position_y_), icon_);
}

void Player::CheckLive() {
  if (hunger_ < 1) {
    is_dead_ = true;
  }
}

void Player::Update() {
  CheckLive();
  Move();
  Render();
}

int Player::PosX() const {
  return position_x_;
}

int Player::PosY() const {
  return position_y_;
}

int Player::GetHunger() const {
  return hunger_;
}

int Player::GetSteps() const {
  return steps_;
}

int Player::GetCoins() const {
  return coins_;
}

void Player::CoinCollect(int coins_cost) {
  coins_ += coins_cost;
}

void Player::FoodCollect(int food_cost) {
  hunger_ += food_cost;
}

bool Player::IsDead() const {
  return is_dead_;
}

void Player::PutWalkStatusR(bool status) {
  walk_status_right_ = status;
}

void Player::PutWalkStatusL(bool status) {
  walk_status_left_ = status;
}

void Player::PutWalkStatusUp(bool status) {
  walk_status_up_ = status;
}

void Player::PutWalkStatusDown(bool status) {
  walk_status_down_ = status;
}
