#ifndef JAVA_COMPILER_H
#define JAVA_COMPILER_H
#include "../../../serve/compiler/Compiler.h"

class JavaCompiler : public Compiler {
public:
  void compile(std::string filepath);
};

#endif
