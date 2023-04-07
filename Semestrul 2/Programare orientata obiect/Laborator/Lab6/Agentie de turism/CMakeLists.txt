cmake_minimum_required(VERSION 3.25)
project(Agentie_de_turism)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Agentie_de_turism
        AgentieService.cpp
        AgentieService.h
        consola.cpp
        consola.h
        main.cpp
        Oferta.cpp
        Oferta.h
        OfertaRepo.cpp
        OfertaRepo.h
        teste.cpp
        teste.h
        )

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")
