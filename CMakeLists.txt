cmake_minimum_required(VERSION 3.16)

project(qt_lab1 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set(PROJECT_SOURCES
    src/main.cpp
    src/greetingform.cpp
    src/greetingform.hpp
    src/greetingform.ui
    src/calculatorform.cpp
    src/calculatorform.hpp
    src/calculatorform.ui
)

add_executable(qt_lab1 ${PROJECT_SOURCES})

target_link_libraries(qt_lab1 PRIVATE 
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

set_target_properties(qt_lab1 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build"
)
