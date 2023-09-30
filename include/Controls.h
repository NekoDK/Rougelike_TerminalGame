
#ifndef INCLUDE_CONTROLS_H_
#define INCLUDE_CONTROLS_H_

class Controls {
  bool is_up_ = false;
  bool is_down_ = false;
  bool is_right_ = false;
  bool is_left_ = false;
  bool is_exit_ = false;

 public:
  bool IsUp() const;
  bool IsDown() const;
  bool IsLeft() const;
  bool IsRight() const;
  bool IsExit() const;

  void Update();
};

#endif  // INCLUDE_CONTROLS_H_
