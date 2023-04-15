#ifndef RUNNER_H
#define RUNNER_H
#include "../../Common.h"

class Runner {
public:
  virtual ~Runner() {}
  virtual void run(std::string filepath) = 0;
};

#endif // RUNNER_H
