#ifndef RUNNER_H
#define RUNNER_H
#include "../../Common.h"

class Runner {
public:
  virtual ~Runner() {}
  virtual void run(std::string filepath) = 0;
  std::string getExecutableName(std::string filepath) {
    std::string executableName = filepath.substr(0, filepath.find_last_of("."));
    return executableName + "\"";
  }
};

#endif // RUNNER_H
