CC=g++
CFLAGS=-Wall -std=c++17
INC=-Isrc

SRC=src/languages/cpp/CppRunner.cpp \
    src/languages/cpp/cppCompiler/CppCompiler.cpp \
    src/languages/java/JavaRunner.cpp \
    src/languages/java/javaCompiler/JavaCompiler.cpp \
		src/serve/FileWatcher.cpp \
    src/serve/compiler/Compiler.cpp \
    src/serve/runner/Runner.cpp \
    src/codeRunnerXZ.cpp

OBJ=obj/languages/cpp/CppRunner.o \
    obj/languages/cpp/cppCompiler/CppCompiler.o \
    obj/languages/java/JavaRunner.o \
    obj/languages/java/javaCompiler/JavaCompiler.o \
		obj/serve/FileWatcher.o \
    obj/serve/compiler/Compiler.o \
    obj/serve/runner/Runner.o \
    obj/codeRunnerXZ.o

all: codeRunnerXZ

main: $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o main

obj/languages/cpp/CppRunner.o: src/languages/cpp/CppRunner.cpp
	mkdir -p obj/languages/cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

obj/languages/cpp/cppCompiler/CppCompiler.o: src/languages/cpp/cppCompiler/CppCompiler.cpp
	mkdir -p obj/languages/cpp/cppCompiler
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

obj/languages/java/JavaRunner.o: src/languages/java/JavaRunner.cpp
	mkdir -p obj/languages/java
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

obj/languages/java/javaCompiler/JavaCompiler.o: src/languages/java/javaCompiler/JavaCompiler.cpp 
	mkdir -p obj/languages/java/javaCompiler
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

obj/codeRunnerXZ.o: src/codeRunnerXZ.cpp
	mkdir -p obj
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf obj/* codeRunnerXZ
