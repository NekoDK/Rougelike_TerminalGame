#include <BearLibTerminal.h>
#include <Obstacle-manager.h>
#include <TextLevelReader.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

TextLevelReader::TextLevelReader(const std::string& filename) : filename(filename) {}

void TextLevelReader::levelReader() {
  std::ifstream file(filename);
  if (!file.is_open()) {
    return;
  }
  std::string line;
  int y = 0;
  while (std::getline(file, line)) {
    int x = 0;
    for (char c : line) {
      if (c == '#') {
        // ob->AddWall(x, y);
        // data.AddWall(x, y);
      }
      x++;
    }
    y++;
  }
  file.close();
}
