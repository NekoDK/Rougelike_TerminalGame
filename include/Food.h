#ifndef INCLUDE_FOOD_H_
#define INCLUDE_FOOD_H_

class Food {
  char icon_ = '%';
  int food_cost_;
  int position_x_;
  int position_y_;

  void Render();

 public:
  Food(int position_x, int position_y, int food_cost)
      : position_x_(position_x), position_y_(position_y), food_cost_(food_cost) {}

  void Update();

  int PosX() const;
  int PosY() const;
  int GetFoodCost() const;
};

#endif  // INCLUDE_FOOD_H_
