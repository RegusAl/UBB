cmake_minimum_required(VERSION 3.24)
project(Cofetarie C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Cofetarie
        MateriePrima.c
        MateriePrima.h
        repository.c
        repository.h
        service.c
        service.h
        teste.c
        teste.h
        ui.c)
