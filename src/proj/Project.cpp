#include <BearLibTerminal.h>
#include <proj/controls.h>
#include <proj/scenes/game_scene.h>

#include "lib/scenes/scene_manager.h"
#include "proj/scenes/game_over_scene.h"
#include "proj/scenes/game_scene2.h"
#include "proj/scenes/title_scene.h"

int main() {
  terminal_open();
  terminal_refresh();

  Controls controls;

  Context ctx{};  // создаем контекст на стеке в самом начале приложения
  SceneManager sm(ctx);  // создаем менеджер сцен на стеке
  // Регистрируем сцены в менеджер. Обратите внимание,
  // что деструкторы над сценами вызывать здесь не надо, так как изх вызовет менеджер.
  sm.Put("title", new TitleScene(&ctx, controls));
  sm.Put("game", new GameScene(&ctx, controls));
  sm.Put("game_over", new GameOverScene(&ctx, controls));
  sm.Put("game2", new GameScene2(&ctx, controls));

  // Выставляем текущую сцену
  ctx.scene_ = "title";

  // Ждем, пока пользователь не закроет окно
  while (true) {
    controls.OnUpdate();
    if (controls.IsPressed(TK_CLOSE)) {
      break;
    }

    sm.OnRender();

    controls.Reset();
  }
  sm.OnExit();

  terminal_close();
}
