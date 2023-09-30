#ifndef INCLUDE_LEVELREADER_H_
#define INCLUDE_LEVELREADER_H_

#include <Obstacle.h>

class LevelReader {
 public:
  virtual ~LevelReader() {}
  virtual void levelReader() = 0;
};

#endif  // INCLUDE_LEVELREADER_H_
