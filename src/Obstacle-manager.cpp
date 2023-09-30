#include <BearLibTerminal.h>
#include <Obstacle-manager.h>

#include <iostream>
int to_pos(float x);

void ObstaclesManager::Update() {
  for (auto it = food.begin(); it != food.end();) {
    it->Update();
    if (player_->PosX() == it->PosX() && player_->PosY() == it->PosY()) {
      player_->FoodCollect(it->GetFoodCost());
      food.erase(it);
    } else {
      ++it;
    }
  }

  for (auto it = coins.begin(); it != coins.end();) {
    it->Update();
    if (player_->PosX() == it->PosX() && player_->PosY() == it->PosY()) {
      player_->CoinCollect(it->GetCoinsCost());
      coins.erase(it);
    } else {
      ++it;
    }
  }

  state_collision = true;
  for (auto &ob : obstacles) {  // right
    ob.Update();
    if (player_->PosX() == to_pos(ob.PosX()) - 1 && player_->PosY() == to_pos(ob.PosY())) {
      state_collision = false;
    }
    player_->PutWalkStatusR(state_collision);
  }

  state_collision = true;
  for (auto &ob : obstacles) {  // left
    ob.Update();
    if (player_->PosX() == to_pos(ob.PosX()) + 1 && player_->PosY() == to_pos(ob.PosY())) {
      state_collision = false;
    }
    player_->PutWalkStatusL(state_collision);
  }

  state_collision = true;
  for (auto &ob : obstacles) {  // up
    ob.Update();
    if (player_->PosX() == to_pos(ob.PosX()) && player_->PosY() == to_pos(ob.PosY()) + 1) {
      state_collision = false;
    }
    player_->PutWalkStatusUp(state_collision);
  }

  state_collision = true;
  for (auto &ob : obstacles) {  // up
    ob.Update();
    if (player_->PosX() == to_pos(ob.PosX()) && player_->PosY() == to_pos(ob.PosY()) - 1) {
      state_collision = false;
    }
    player_->PutWalkStatusDown(state_collision);
  }
}

void ObstaclesManager::AddWall(int x, int y) {
  obstacles.push_back(Obstacle(x, y));
}
