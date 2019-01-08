cmake_minimum_required(VERSION 3.5)
project(wee)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/distance.c
        src/distance.h
        src/history.c
        src/history.h
        src/util.h
        src/wee.c
        src/wee.h)

add_executable(wee ${SOURCE_FILES})