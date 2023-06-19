cmake_minimum_required(VERSION 3.25)
project(SESIUNE_PRACTIC)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Ot/6.5.0/gcc_64/lib/cmake")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(SESIUNE_PRACTIC main.cpp repository.cpp repository.h service.cpp service.h domain.cpp domain.h GUI.cpp GUI.h teste.cpp teste.h)
target_link_libraries(SESIUNE_PRACTIC
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

