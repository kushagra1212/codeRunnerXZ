#ifndef FILEWATCHER_H
#define FILEWATCHER_H
#include "../Common.h"
#include "compiler/Compiler.h"
#include "runner/Runner.h"

class FileWatcher {
public:
  FileWatcher(std::string filepath);
  void watch();
  std::string getFileExtension(std::string filepath);

  std::unique_ptr<Compiler> getCompiler(std::string filepath);
  std::unique_ptr<Runner> getRunner(std::string filepath);

private:
  std::string filepath;
  time_t lastModifiedTime;
  std::unique_ptr<Compiler> compiler;
  std::unique_ptr<Runner> runner;
  bool isFileModified(std::string filepath);

  time_t getLastModifiedTime(std::string filepath);

  void compileAndRun();
};

#endif
