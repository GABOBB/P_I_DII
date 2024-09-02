cmake_minimum_required(VERSION 3.28)
project(MPointers)

set(CMAKE_CXX_STANDARD 17)

add_executable(MPointers main.cpp
        MP/Mpointer.cpp
        MP/Mpointer.h
        MP/MpointerGC.cpp
        MP/MpointerGC.h
        test/DE_List.cpp
        test/DE_List.h
        test/DE_Node.cpp
        test/DE_Node.h
        MP/Mp_l.cpp
        MP/Mp_l.h)
