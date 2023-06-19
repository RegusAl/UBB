cmake_minimum_required(VERSION 3.25)
project(Melodie2)

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

add_executable(Melodie2 main.cpp domain.cpp domain.h GUI.cpp GUI.h service.cpp service.h repository.cpp repository.h teste.cpp teste.cpp teste.h MODEL.h)
target_link_libraries(Melodie2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

