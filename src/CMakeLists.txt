cmake_minimum_required(VERSION 3.14)
set(This calculator)
project(${This} CXX)

set(CMAKE_CXX_STANDARD 11)

set(Headers calculator.h)
set(Sources calculator.cpp)

add_library(${This} STATIC ${Sources} ${Headers})
