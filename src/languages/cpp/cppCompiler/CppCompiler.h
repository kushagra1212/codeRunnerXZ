#ifndef CPPCOMPILER_H
#define CPPCOMPILER_H

#include "../../../serve/compiler/Compiler.h"

class CppCompiler : public Compiler {
public:
  void compile(std::string filepath);
};

#endif
