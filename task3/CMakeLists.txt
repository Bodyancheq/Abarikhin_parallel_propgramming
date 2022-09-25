cmake_minimum_required(VERSION 3.23)
project(task3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -fopenmp)

add_executable(task3 task1/task1.cpp)

