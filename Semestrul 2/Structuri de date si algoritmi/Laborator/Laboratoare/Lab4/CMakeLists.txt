cmake_minimum_required(VERSION 3.25)
project(Lab4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab4
        App.cpp
        IteratorMDO.cpp
        IteratorMDO.h
        IteratorVal.cpp
        IteratorVal.h
        MDO.cpp
        MDO.h
        TestExtins.cpp
        TestExtins.h
        TestScurt.cpp
        TestScurt.h)
