#include "CppRunner.h"

void CppRunner::run(std::string filepath) {
  std::string executableName = getExecutableName(filepath);
  std::string command = "./" + executableName;
  std::cout << "Command to run: " << command << std::endl;
  command = command.substr(2);
  system(command.c_str());
}

std::string CppRunner::getExecutableName(std::string filepath) {
  size_t lastDotIndex = filepath.find_last_of(".");
  std::string executableName = filepath.substr(0, lastDotIndex);
  return executableName;
}
