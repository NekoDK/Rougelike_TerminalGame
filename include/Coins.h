#ifndef INCLUDE_COINS_H_
#define INCLUDE_COINS_H_

class Coins {
  char icon_ = '$';
  int position_x_;
  int position_y_;
  int coins_cost_;

  void Render();

 public:
  Coins(int position_x, int position_y, int coins_cost)
      : position_x_(position_x), position_y_(position_y), coins_cost_(coins_cost) {}

  void Update();

  int PosX() const;
  int PosY() const;
  int GetCoinsCost() const;
};

#endif  // INCLUDE_COINS_H_
