#ifndef INCLUDE_PROJ_ILEVELREADER_H_
#define INCLUDE_PROJ_ILEVELREADER_H_

#include <iostream>
#include <string>

#include "lib/ecs/entity_manager.h"
class ILevelReader {
 public:
  virtual ~ILevelReader() {}
  virtual void ReadLevel(const std::string& filePath, EntityManager* entityManager) = 0;
};
#endif  // INCLUDE_PROJ_ILEVELREADER_H_
