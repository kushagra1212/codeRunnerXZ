#ifndef COMPILER_H
#define COMPILER_H
#include "../../Common.h"
class Compiler {
public:
  virtual ~Compiler() {}
  virtual void compile(std::string filePath) = 0;
  std::string getExecutableName(std::string filepath) {
    std::string executableName = filepath.substr(0, filepath.find_last_of("."));
    return executableName + "\"";
  }
};

#endif // COMPILER_H
