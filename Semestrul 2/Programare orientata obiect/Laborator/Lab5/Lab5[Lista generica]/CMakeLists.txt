cmake_minimum_required(VERSION 3.24)
project(Lab5 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Lab5
        customSort.c
        customSort.h
        farmacie_service.c
        farmacie_service.h
        main.c
        medicament.c
        medicament.h
        MyList.c
        MyList.h)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}-Wall -Wextra")