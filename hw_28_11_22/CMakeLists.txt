cmake_minimum_required(VERSION 3.23)
project(hw_28_11_22)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -fopenmp)

add_executable(hw
        task1.cpp task2.cpp)
