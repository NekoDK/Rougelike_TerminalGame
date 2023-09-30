#ifndef INCLUDE_PLAYER_H_
#define INCLUDE_PLAYER_H_

#include <Controls.h>

class Player {
  const Controls &controls;
  char icon_;
  float speed_;
  int position_x_;
  int position_y_;
  bool is_dead_ = false;

  void Render();
  void GetBack();
  void Move();

  int coins_ = 0;
  int hunger_ = 200;
  int steps_ = 0;
  bool walk_status_right_ = true;
  bool walk_status_up_ = true;
  bool walk_status_down_ = true;
  bool walk_status_left_ = true;

 public:
  Player(const Controls &controls, char icon, float speed, int position_x, int position_y)
      : controls(controls), icon_(icon), speed_(speed), position_x_(position_x), position_y_(position_y) {}

  void Update();

  int PosX() const;
  int PosY() const;
  int GetHunger() const;
  int GetCoins() const;
  int GetSteps() const;
  bool IsDead() const;

  void PutWalkStatusR(bool status);
  void PutWalkStatusL(bool status);
  void PutWalkStatusUp(bool status);
  void PutWalkStatusDown(bool status);
  void CheckLive();
  void CoinCollect(int coins_cost);
  void FoodCollect(int food_cost);
};

#endif  // INCLUDE_PLAYER_H_
