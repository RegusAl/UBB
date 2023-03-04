cmake_minimum_required(VERSION 3.24)
project(TAD_Colectie)

set(CMAKE_CXX_STANDARD 14)

include_directories("Proiect C++/Colectie")
include_directories("Proiect C++/Colectie (cu rel)")
include_directories(Teste)
include_directories("Teste (cu relatie)")

add_executable(TAD_Colectie
        "Proiect C++/Colectie/App.cpp"
        "Proiect C++/Colectie/Colectie.cpp"
        "Proiect C++/Colectie/Colectie.h"
        "Proiect C++/Colectie/IteratorColectie.cpp"
        "Proiect C++/Colectie/IteratorColectie.h"
        "Proiect C++/Colectie (cu rel)/App.cpp"
        "Proiect C++/Colectie (cu rel)/Colectie.cpp"
        "Proiect C++/Colectie (cu rel)/Colectie.h"
        "Proiect C++/Colectie (cu rel)/IteratorColectie.cpp"
        "Proiect C++/Colectie (cu rel)/IteratorColectie.h"
        Teste/TestExtins.cpp
        Teste/TestExtins.h
        Teste/TestScurt.cpp
        Teste/TestScurt.h
        "Teste (cu relatie)/TestExtins.cpp"
        "Teste (cu relatie)/TestExtins.h"
        "Teste (cu relatie)/TestScurt.cpp"
        "Teste (cu relatie)/TestScurt.h")
