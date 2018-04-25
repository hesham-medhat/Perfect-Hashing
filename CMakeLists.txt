cmake_minimum_required(VERSION 3.10)
project(Perfect_Hashing)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(include)
include_directories(include/cs223)

add_executable(Perfect_Hashing
        src/main.cpp
        include/cs223/PerfectHashTable.h
        include/cs223/HighLevelHashTable.h
        include/cs223/LowLevelHashTable.h
        include/cs223/MatrixHashFunction.h
        src/LowLevelHashTable.cpp
        src/HighLevelHashTable.cpp
        src/MatrixHashFunction.cpp)
