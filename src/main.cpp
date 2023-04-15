#include "Common.h"
#include "languages/cpp/CppRunner.h"
#include "languages/cpp/cppCompiler/CppCompiler.h"
#include "serve/FileWatcher.h"

int main(int argc, char **argv) {
  std::string filepath;
  std::cout << "Enter the absolute file path of the .cpp file: ";
  getline(std::cin, filepath);
  std::cout << "filepath: " << filepath << std::endl;
  std::unique_ptr<Compiler> compiler(new CppCompiler());
  std::unique_ptr<Runner> runner(new CppRunner());
  std::unique_ptr<FileWatcher> fileWatcher(
      new FileWatcher(filepath, std::move(compiler), std::move(runner)));
  fileWatcher->watch();
   return 0;
}
