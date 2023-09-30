#include "txt_lvl_read.h"
#include"proj/controls.h"
#include <proj/components/collider_component.h>
#include <proj/components/gravity_component.h>
#include <proj/components/jump_component.h>
#include <proj/components/player_control_component.h>
#include <proj/systems/ai_system.h>
#include <proj/systems/collision_system.h>
#include <proj/systems/game_over_system.h>
#include <proj/systems/gravity_system.h>
#include<proj/systems/jump_control_system.h>
#include <proj/systems/precollision_system.h>
#include <proj/systems/statistic_system.h>

#include "lib/math/vec2.h"
#include "proj/components/coin_component.h"
#include "proj/components/enemy_component.h"
#include "proj/components/id_component.h"
#include "proj/components/movement_component.h"
#include "proj/components/obstacle_component.h"
#include "proj/components/precollider_component.h"
#include "proj/components/statistic_component.h"
#include "proj/components/texture_component.h"
#include "proj/components/transform_component.h"
#include "proj/components/wall_component.h"
#include "proj/systems/delete_system.h"
#include "proj/systems/movement_system.h"
#include "proj/systems/obstacles_control_system.h"
#include "proj/systems/rendering_system.h"

void TextLevelReader::ReadLevel(const std::string& filePath, EntityManager* entityManager) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        // Обработка ошибки открытия файла
        std::cerr << "Error opening file: " << filePath << std::endl;
        return;
    }

    std::string line;
    int y = 0;
    while (std::getline(file, line)) {
        std::cout << "reading start 1" << std::endl;
        for (int x = 0; x < static_cast<int>(line.size()); ++x) {
            std::cout << "reading start 2" << std::endl;
            char symbol = line[x];
            if (symbol == '@') {
                auto player = entityManager->CreateEntity();
                player->Add<TransformComponent>(Vec2(x, y));
                player->Add<TextureComponent>('@');
                player->Add<MovementComponent>(ZeroVec2, RightVec2);
                player->Add<JumpComponent>(1,2);
                player->Add<PlayerControlComponent>(TK_UP, TK_DOWN, TK_RIGHT, TK_LEFT);
                player->Add<ColliderComponent>(OnesVec2, ZeroVec2);
                player->Add<StatisticComponent>(0, 0, 0);
                player->Add<ObstacleComponent>();
                std::cout << "player spawned";

            } else if (symbol == '%') {
                auto coin = entityManager->CreateEntity();
                coin->Add<TransformComponent>(Vec2(x, y));
                coin->Add<TextureComponent>('%');
                coin->Add<ObstacleComponent>();
                coin->Add<ColliderComponent>(OnesVec2, ZeroVec2);
                coin->Add<CoinComponent>(10);
                std::cout << "money spawned";
            } else if (symbol == '#') {
                auto wall = entityManager->CreateEntity();
                wall->Add<TransformComponent>(Vec2(x, y));
                wall->Add<TextureComponent>('#');
                std::cout << "wall spawned";
            }
        }
        ++y;
        std::cout << "Reading str complite!" << std::endl;
    }
    std::cout << "Reading is end!" << std::endl;

}

