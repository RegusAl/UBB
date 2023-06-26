cmake_minimum_required(VERSION 3.25)
project(Lab3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab3
        IteratorMultime.cpp
        IteratorMultime.h
        "App.cpp"
        Multime.cpp
        Multime.h
        TestExtins.cpp
        TestExtins.h
        TestScurt.cpp
        TestScurt.h)
