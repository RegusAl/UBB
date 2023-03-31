cmake_minimum_required(VERSION 3.24)
project(Cofetarie_Alocare_Dinamica_ C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Cofetarie_Alocare_Dinamica_
        MateriePrima.c
        MateriePrima.h
        repository.c
        repository.h
        service.c
        service.h
        teste.c
        teste.h
        ui.c)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}-Wall -Wextra")
