cmake_minimum_required(VERSION 3.25)
project(Agentie_de_turism)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories("/Ot/6.5.0/gcc_64/include")
include_directories("/Ot/6.5.0/gcc_64/include/QtCore")
include_directories("/Ot/6.5.0/gcc_64/include/QtGui")
include_directories("/Ot/6.5.0/gcc_64/include/QtWidgets")


add_executable(Agentie_de_turism
        AgentieService.cpp
        AgentieService.h
        consola.cpp
        consola.h
        CosOferte.cpp
        CosOferte.h
        Errors.h
        main.cpp
        Oferta.cpp
        Oferta.h
        OfertaRepo.cpp
        OfertaRepo.h
        teste.cpp
        teste.h
        Validator.cpp
        Validator.h
        Undo.h
        RepoLab.cpp
        OfertaStoreGUI.h
        OfertaStoreGUI.cpp)
