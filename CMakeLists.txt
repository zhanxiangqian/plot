cmake_minimum_required(VERSION 3.1.0)

project(plotDemo)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

add_subdirectory(plotView)

include_directories(plotView)

add_executable(plotDemo
    main.cpp
	mainWindow.cpp
	mainWindow.ui
)

target_link_libraries(plotDemo plotView Qt5::Core Qt5::Gui Qt5::Widgets)

install(TARGETS plotDemo
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)