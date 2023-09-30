#ifndef INCLUDE_PROJ_TXT_LVL_READ_H_
#define INCLUDE_PROJ_TXT_LVL_READ_H_

#include <fstream>
#include <string>

#include "lib/ecs/entity_manager.h"
#include "proj/ilevelreader.h"

class TextLevelReader : public ILevelReader {
 public:
  void ReadLevel(const std::string& filePath, EntityManager* entityManager) override;
};

#endif  // INCLUDE_PROJ_TXT_LVL_READ_H_
