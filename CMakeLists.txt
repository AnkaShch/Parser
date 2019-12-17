cmake_minimum_required(VERSION 3.15)
project(parser)

set(CMAKE_CXX_STANDARD 17)

add_executable(parser main.cpp src/LexicalAnalyzer.cpp src/LexicalAnalyzer.h src/Tree.cpp src/Tree.h src/Parser.cpp src/Parser.h src/Test.cpp src/Test.h)