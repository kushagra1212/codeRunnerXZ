cmake_minimum_required(VERSION 3.5)
project(codeRunnerXZ)

set(CMAKE_CXX_STANDARD 17)


file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(codeRunnerXZ ${SOURCES})
target_include_directories(codeRunnerXZ PRIVATE src)


set_target_properties(codeRunnerXZ PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
