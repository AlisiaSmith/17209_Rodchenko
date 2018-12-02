cmake_minimum_required(VERSION 3.10)
project(hash)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(tests)

add_executable(hash
        HashTable.cpp
        HashTable.h
        Header.h
        Pair.cpp
        Pair.h
        source.cpp
        Value.cpp
        Value.h)

add_executable(tests
    tests.cpp)
