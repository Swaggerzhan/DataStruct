cmake_minimum_required(VERSION 3.5)
project(DataStruct)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataStruct main.cpp Tree/BinaryTree.h Tree/Tree_test.h Sort/mergeSort.h Sort/SortTestHelper.h)