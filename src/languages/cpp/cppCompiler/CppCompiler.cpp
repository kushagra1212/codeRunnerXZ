#include "CppCompiler.h"

void CppCompiler::compile(std::string filepath) {
  std::string command =
      "g++ " + filepath + " -o " + getExecutableName(filepath);
  system(command.c_str());
}

std::string CppCompiler::getExecutableName(std::string filepath) {
  size_t lastDotIndex = filepath.find_last_of(".");
  std::string executableName = filepath.substr(0, lastDotIndex);
  return executableName;
}
