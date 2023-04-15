#ifndef FILEWATCHER_H
#define FILEWATCHER_H
#include "../Common.h"
#include "compiler/Compiler.h"
#include "runner/Runner.h"

class FileWatcher {
public:
  FileWatcher(std::string filepath, Compiler *compiler, Runner *runner);

  void watch();

private:
  std::string filepath;
  time_t lastModifiedTime;
  Compiler *compiler;
  Runner *runner;

  bool isFileModified(std::string filepath);

  time_t getLastModifiedTime(std::string filepath);

  void compileAndRun();
};

#endif
