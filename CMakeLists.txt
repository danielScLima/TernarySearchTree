cmake_minimum_required(VERSION 3.5.1)
project(Program VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(
	libternarysearchtree
	NodeOfTernarySearchTree.h
	ternarysearchtree.h
	ternarysearchtree.cpp
)

add_executable(program program.cpp)

target_link_libraries(program PRIVATE libternarysearchtree)
