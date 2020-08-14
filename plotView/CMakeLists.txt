cmake_minimum_required(VERSION 3.1.0)

project(plotView)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Core Gui Widgets Network Svg PrintSupport REQUIRED)


add_library(plotView SHARED
	QtGnuplotEvent.cpp
	QtGnuplotScene.cpp
	QtGnuplotWindow.cpp
	QtGnuplotItems.cpp
	QtGnuplotResource.qrc
	QtGnuplotSettings.ui
	QtGnuplotWidget.cpp 
	QtGnuplotInstance.cpp
	settingsWidget.cpp
	settingsWidget.ui
)

file(GLOB plotView_HDRS *.h)

target_link_libraries(plotView Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Network Qt5::Svg Qt5::PrintSupport)

install(FILES ${plotView_HDRS} DESTINATION include)

install(TARGETS plotView
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)