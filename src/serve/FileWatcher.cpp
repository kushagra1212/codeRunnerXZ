#include "FileWatcher.h"
#include "../languages/cpp/CppRunner.h"
#include "../languages/cpp/cppCompiler/CppCompiler.h"
#include "../languages/java/JavaRunner.h"
#include "../languages/java/javaCompiler/JavaCompiler.h"

FileWatcher::FileWatcher(std::string filepath) {
  this->filepath = filepath;
  this->compiler = std::move(this->getCompiler(filepath));
  this->runner = std::move(this->getRunner(filepath));
  lastModifiedTime = getLastModifiedTime(filepath);
}

std::unique_ptr<Compiler> FileWatcher::getCompiler(std::string filepath) {
  std::string fileExtension = getFileExtension(filepath);
  if (fileExtension == "cpp") {
    return std::make_unique<CppCompiler>();
  } else if (fileExtension == "java") {
    return std::make_unique<JavaCompiler>();
  } else {
    throw std::runtime_error("Unsupported file extension: " + fileExtension);
  }
}

std::unique_ptr<Runner> FileWatcher::getRunner(std::string filepath) {
  std::string fileExtension = getFileExtension(filepath);
  if (fileExtension == "cpp") {
    return std::make_unique<CppRunner>();
  } else if (fileExtension == "java") {
    return std::make_unique<JavaRunner>();
  } else {
    throw std::runtime_error("Unsupported file extension: " + fileExtension);
  }
}

void FileWatcher::watch() {
  compileAndRun();
  while (true) {
    if (isFileModified(filepath)) {
      lastModifiedTime = getLastModifiedTime(filepath);
      compileAndRun();
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

std::string FileWatcher::getFileExtension(std::string filepath) {
  return filepath.substr(filepath.find_last_of(".") + 1);
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
