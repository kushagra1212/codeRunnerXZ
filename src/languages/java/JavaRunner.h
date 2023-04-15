#ifndef JAVA_RUNNER_H
#define JAVA_RUNNER_H

#include "../../serve/runner/Runner.h"

class JavaRunner : public Runner {
public:
  void run(std::string filepath);
};

#endif
