#ifndef CPPCOMPILER_H
#define CPPCOMPILER_H

#include "../../../serve/Compiler/Compiler.h"

class CppCompiler : public Compiler {
public:
  void compile(std::string filepath);

private:
  std::string getExecutableName(std::string filepath);
};

#endif
