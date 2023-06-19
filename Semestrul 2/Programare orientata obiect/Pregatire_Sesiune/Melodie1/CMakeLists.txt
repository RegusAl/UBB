cmake_minimum_required(VERSION 3.25)
project(Pregatire_Sesiune)

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

add_executable(Pregatire_Sesiune main.cpp domain.cpp domain.h teste.cpp teste.h repo.cpp repo.h service.cpp service.h GUI.cpp GUI.h MODEL.h)
target_link_libraries(Pregatire_Sesiune
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

