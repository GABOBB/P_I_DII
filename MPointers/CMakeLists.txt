cmake_minimum_required(VERSION 3.28)
project(MPointers)

set(CMAKE_CXX_STANDARD 17)

add_executable(MPointers main.cpp
        Mpointer.cpp
        Mpointer.h)
