cmake_minimum_required(VERSION 3.25)
project(Lab_12)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab_12
        CosCRUDGUI.h
        Cos_Oferte.cpp
        Cos_Oferte.h
        CosReadOnlyGUI.h
        main.cpp
        TableModel.h
        observer.h
        oferta.cpp
        oferta.h
        OfertaStoreGUI.cpp
        OfertaStoreGUI.h
        Repo.cpp
        Repo.h
        Service.cpp
        Service.h
        StoreGUIModele.cpp
        StoreGUIModele.h
        Teste.cpp
        Teste.h
        Undo.h
        Validator.cpp
        Validator.h)
