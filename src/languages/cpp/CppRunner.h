#ifndef CPPRUNNER_H
#define CPPRUNNER_H

#include "../../serve/runner/Runner.h"

class CppRunner : public Runner {
public:
  void run(std::string filepath);
};

#endif
