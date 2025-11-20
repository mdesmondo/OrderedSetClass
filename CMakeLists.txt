cmake_minimum_required(VERSION 4.0)
project(lab4)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab4 source.cpp OrderedSet.cpp test.cpp autoTests.cpp interactiveTests.cpp)
