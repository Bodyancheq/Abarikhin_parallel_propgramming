cmake_minimum_required(VERSION 3.23)
project(cw4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -fopenmp)

add_executable(cw4 task1.cpp task2.cpp task3.cpp task4.cpp)
