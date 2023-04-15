#include "FileWatcher.h"

FileWatcher::FileWatcher(std::string filepath, Compiler *compiler,
                         Runner *runner) {
  this->filepath = filepath;
  this->compiler = compiler;
  this->runner = runner;
  lastModifiedTime = getLastModifiedTime(filepath);
}

void FileWatcher::watch() {
  while (true) {
    if (isFileModified(filepath)) {
      lastModifiedTime = getLastModifiedTime(filepath);
      compileAndRun();
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

bool FileWatcher::isFileModified(std::string filepath) {
  time_t currentModifiedTime = getLastModifiedTime(filepath);
  return difftime(currentModifiedTime, lastModifiedTime) > 0;
}

time_t FileWatcher::getLastModifiedTime(std::string filepath) {
  struct stat fileAttributes;
  stat(filepath.c_str(), &fileAttributes);
  return fileAttributes.st_mtime;
}

void FileWatcher::compileAndRun() {
  std::cout << "Compiling " << filepath << "..." << std::endl;
  compiler->compile(filepath);
  std::cout << "Running " << filepath << "..." << std::endl;
  runner->run(filepath);
}
