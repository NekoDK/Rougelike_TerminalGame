
#ifndef INCLUDE_OBSTACLE_MANAGER_H_
#define INCLUDE_OBSTACLE_MANAGER_H_

#include <Coins.h>
#include <Food.h>
#include <Obstacle.h>
#include <Player.h>

#include <vector>

class ObstaclesManager {
  Player *player_;
  std::vector<Coins> coins{{20, 20, 1}, {15, 15, 2}, {10, 10, 3}};
  std::vector<Food> food{{15, 10, 60}, {55, 10, 50}, {35, 10, 67}, {20, 10, 40}};
  std::vector<Obstacle> obstacles{};

 public:
  explicit ObstaclesManager(Player *player) : player_(player) {}

  void AddWall(int x, int y);
  bool state_collision = false;
  void Update();
};

#endif  // INCLUDE_OBSTACLE_MANAGER_H_
