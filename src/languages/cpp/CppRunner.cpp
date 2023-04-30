#include "CppRunner.h"

void CppRunner::run(std::string filepath) {
  std::string executableName = getExecutableName(filepath);
  std::string command = "./" + executableName;
  command = command.substr(2);
  system(command.c_str());
}
