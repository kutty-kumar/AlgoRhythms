cmake_minimum_required(VERSION 3.9)
project(AlgoRhythms)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(AlgoRhythms
        DynamicProgramming.h
        main.cpp DivideAndConquer.h Sorting.h Utils.h BinaryTrees.h Searching.h)
