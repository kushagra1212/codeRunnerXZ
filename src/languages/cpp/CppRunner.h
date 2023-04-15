#ifndef CPPRUNNER_H
#define CPPRUNNER_H

#include "../../serve/runner/Runner.h"

class CppRunner : public Runner {
public:
  void run(std::string filepath);

private:
  std::string getExecutableName(std::string filepath);
};

#endif
