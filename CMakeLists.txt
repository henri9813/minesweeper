cmake_minimum_required(VERSION 3.9)
project(MineSweeper)

set(CMAKE_CXX_STANDARD 11)

add_executable(MineSweeper main.cpp Plateau.cpp Plateau.h Case.cpp Case.h)