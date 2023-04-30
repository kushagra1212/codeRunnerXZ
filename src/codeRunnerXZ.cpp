#include "Common.h"
#include "languages/cpp/CppRunner.h"
#include "languages/cpp/cppCompiler/CppCompiler.h"
#include "serve/FileWatcher.h"

std::string sanatisedFilePaths(std::string filepath) {
  return (std::string)("\"" + filepath.substr(filepath.find_first_of('/')) +
                       "\"");
}

int main(int argc, char **argv) {
  std::string filepath;
  std::cout << "Enter the absolute file path of the .cpp or .java file: ";
  getline(std::cin, filepath);
  filepath = sanatisedFilePaths(filepath);
  std::cout << "filepath: " << filepath << std::endl;
  std::unique_ptr<FileWatcher> fileWatcher(new FileWatcher(filepath));
  fileWatcher->watch();
  return 0;
}
