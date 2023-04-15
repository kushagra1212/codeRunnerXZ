CC=g++
CFLAGS=-Wall -std=c++17
INC=-Isrc

SRC=src/languages/cpp/cppRunner.cpp \
    src/languages/cpp/cppCompiler/CppCompiler.cpp \
    src/serve/FileWatcher.cpp \
    src/serve/compiler/Compiler.cpp \
    src/serve/runner/Runner.cpp \
    src/main.cpp

OBJ=obj/languages/cpp/cppRunner.o \
    obj/languages/cpp/cppCompiler/CppCompiler.o \
    obj/serve/FileWatcher.o \
    obj/serve/compiler/Compiler.o \
    obj/serve/runner/Runner.o \
    obj/main.o

all: main

main: $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o main

obj/languages/cpp/cppRunner.o: src/languages/cpp/cppRunner.cpp
	mkdir -p obj/languages/cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

obj/languages/cpp/cppCompiler/CppCompiler.o: src/languages/cpp/cppCompiler/CppCompiler.cpp
	mkdir -p obj/languages/cpp/cppCompiler
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

obj/serve/FileWatcher.o: src/serve/FileWatcher.cpp
	mkdir -p obj/serve
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

obj/serve/compiler/Compiler.o: src/serve/compiler/Compiler.cpp
	mkdir -p obj/serve/compiler
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

obj/serve/runner/Runner.o: src/serve/runner/Runner.cpp
	mkdir -p obj/serve/runner
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

obj/main.o: src/main.cpp
	mkdir -p obj
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf obj/* main
