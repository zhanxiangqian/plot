cmake_minimum_required(VERSION 3.1.0)

project(plotView)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_definitions(-DPLOTVIEW_LIBRARY)
set(CMAKE_DEBUG_POSTFIX _d)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()


find_package(Qt5 COMPONENTS Core Gui Widgets Network Svg PrintSupport REQUIRED)

set(publicUI 
	QtGnuplotSettings.ui
	settingsWidget.ui
)

add_library(plotView SHARED
	QtGnuplotEvent.cpp
	QtGnuplotScene.cpp
	QtGnuplotWindow.cpp
	QtGnuplotItems.cpp
	QtGnuplotResource.qrc
	QtGnuplotWidget.cpp 
	QtGnuplotInstance.cpp
	settingsWidget.cpp
	${publicUI}
)


set(UIC_HDRS_DIR "${CMAKE_CURRENT_BINARY_DIR}/plotView_autogen/include_$<CONFIG>")

target_include_directories(plotView PUBLIC ${UIC_HDRS_DIR})

file(GLOB plotView_HDRS *.h)
target_link_libraries(plotView Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Network Qt5::Svg Qt5::PrintSupport)

FOREACH(var ${publicUI})
#message("** ${var}")
string(REGEX REPLACE ".ui" ".h" uiHeader ${var})
#message("** ${uiHeader}")
list(APPEND publicUI_HDRS ${UIC_HDRS_DIR}/ui_${uiHeader})
ENDFOREACH()

#message("** ${publicUI_HDRS}")

install(FILES ${plotView_HDRS} DESTINATION include)
install(FILES ${publicUI_HDRS} DESTINATION include)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)

install(TARGETS plotView
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)