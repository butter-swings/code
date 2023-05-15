cmake_minimum_required(VERSION 3.5)

project(qt_learing_2_3 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(qt_learing_2_3
  main.cpp
  dialog.cpp
  dialog.h
)

target_link_libraries(qt_learing_2_3 PRIVATE Qt5::Widgets)
