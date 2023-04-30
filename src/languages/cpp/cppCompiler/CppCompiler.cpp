#include "CppCompiler.h"

void CppCompiler::compile(std::string filepath) {
  std::string command =
      "g++ " + filepath + " -o " + getExecutableName(filepath);
  std::cout << "[Command]: " << command << '\n';
  system(command.c_str());
}
