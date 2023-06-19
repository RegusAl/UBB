cmake_minimum_required(VERSION 3.25)
project(TableMODEL)

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

add_executable(TableMODEL main.cpp GUI.cpp GUI.h domain.cpp domain.h repository.cpp repository.h teste.cpp teste.h service.cpp service.h MyTableModel.h MyListModel.h)
target_link_libraries(TableMODEL
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

