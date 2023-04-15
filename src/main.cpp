#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <sys/stat.h>
#include <thread>

#include "languages/cpp/CppRunner.h"
#include "languages/cpp/cppCompiler/CppCompiler.h"
#include "serve/FileWatcher.h"

int main(int argc, char **argv) {
  std::string filepath;
  std::cout << "Enter the absolute file path of the .cpp file: ";
  getline(std::cin, filepath);
  std::cout << "filepath: " << filepath << std::endl;
  Compiler *cppCompiler = new CppCompiler();
  Runner *cppRunner = new CppRunner();
  FileWatcher *fileWatcher = new FileWatcher(filepath, cppCompiler, cppRunner);
  fileWatcher->watch();

  return 0;
}
