
#include <BearLibTerminal.h>
#include <Controls.h>

void Controls::Update() {
  is_up_ = false;
  is_down_ = false;
  is_left_ = false;
  is_right_ = false;
  is_exit_ = false;

  while (terminal_has_input()) {
    auto key = terminal_read();
    if (key == TK_UP) {
      is_up_ = true;
    }
    if (key == TK_DOWN) {
      is_down_ = true;
    }
    if (key == TK_RIGHT) {
      is_right_ = true;
    }
    if (key == TK_LEFT) {
      is_left_ = true;
    }
    if (key == TK_CLOSE) {
      is_exit_ = true;
    }
  }
}

bool Controls::IsUp() const {
  return is_up_;
}
bool Controls::IsDown() const {
  return is_down_;
}
bool Controls::IsLeft() const {
  return is_left_;
}
bool Controls::IsRight() const {
  return is_right_;
}
bool Controls::IsExit() const {
  return is_exit_;
}
