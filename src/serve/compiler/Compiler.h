#ifndef COMPILER_H
#define COMPILER_H
#include "../../Common.h"
class Compiler {
public:
  virtual ~Compiler() {}
  virtual void compile(std::string filePath) = 0;
};

#endif // COMPILER_H
