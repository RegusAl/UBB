cmake_minimum_required(VERSION 3.25)
project(Lab6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab6
        App.cpp
        IteratorMDO.cpp
        IteratorMDO.h
        MDO.cpp
        MDO.h
        TestExtins.cpp
        TestExtins.h
        TestScurt.cpp
        TestScurt.h)
