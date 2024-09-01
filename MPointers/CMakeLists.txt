cmake_minimum_required(VERSION 3.28)
project(MPointers)

set(CMAKE_CXX_STANDARD 17)

add_executable(MPointers main.cpp
        Mpointer.cpp
        Mpointer.h
        MpointerGC.cpp
        MpointerGC.h
        DE_List.cpp
        DE_List.h
        DE_Node.cpp
        DE_Node.h)
