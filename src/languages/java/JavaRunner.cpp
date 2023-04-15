#include "JavaRunner.h"

void JavaRunner::run(std::string filepath) {

  system(("java " + filepath).c_str());
}
