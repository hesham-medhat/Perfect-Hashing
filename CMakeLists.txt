cmake_minimum_required(VERSION 3.10)
project(Perfect_Hashing)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(include)
include_directories(include/cs223)

add_executable(Perfect_Hashing
        include/cs223/HashTable.h
        include/cs223/HighLevelHashTable.h
        include/cs223/LowLevelHashTable.h
        include/cs223/UniversalHashFamily.h src/main.cpp src/HashTable.cpp src/LowLevelHashTable.cpp src/HighLevelHashTable.cpp src/UniversalHashFamily.cpp)
