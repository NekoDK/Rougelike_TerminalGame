#ifndef INCLUDE_TEXTLEVELREADER_H_
#define INCLUDE_TEXTLEVELREADER_H_

#include <LevelReader.h>
#include <Obstacle.h>

#include <iostream>
#include <string>

class TextLevelReader : public LevelReader {
 public:
  explicit TextLevelReader(const std::string& filename);
  void levelReader() override;

 private:
  std::string filename;
};

#endif  // INCLUDE_TEXTLEVELREADER_H_
