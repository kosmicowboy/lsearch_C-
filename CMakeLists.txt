cmake_minimum_required(VERSION 3.3)
project(lsearch)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp util.cpp util.h)
add_executable(lsearch ${SOURCE_FILES})