set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

cmake_minimum_required(VERSION 3.8)

project(QT_UI LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

include_directories(${PROJECT_SOURCE_DIR}/include/)
aux_source_directory(./src srcs)


set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# QT5 PATH

# MSVC2019_64
set(QT5_PATH "D:/Qt/5.15.2/msvc2019_64/lib/cmake")

# GCC
# set(QT5_PATH "D:/Qt/5.15.2/mingw81_64/lib/cmake")

set(CMAKE_PREFIX_PATH ${QT5_PATH})

# components
find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME} ${srcs})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)
