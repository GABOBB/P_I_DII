cmake_minimum_required(VERSION 3.28)
project(MPointers)

set(CMAKE_CXX_STANDARD 20)

add_executable(MPointers main.cpp
        MP/Mpointer.h
        MP/MpointerGC.cpp
        MP/MpointerGC.h
        test/DoubleEndedList.cpp
        test/DoubleEndedList.h
        test/DoubleEndedNode.cpp
        test/DoubleEndedNode.h
        MP/Mp_l.cpp
        MP/Mp_l.h)

# Enlaza con pthread
target_link_libraries(MPointers PRIVATE pthread)