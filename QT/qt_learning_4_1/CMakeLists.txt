set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

cmake_minimum_required(VERSION 3.8)

project(qt_learning_4_1 LANGUAGES CXX)

set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

# include_directories(${CMAKE_BINARY_DIR})

# add include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

# QT5 PATH

# MSVC2019_64
# set(QT5_PATH "D:/Qt/5.15.2/msvc2019_64/lib/cmake")

# GCC
set(QT5_PATH "E:/Qt/5.15.2/mingw81_64/lib/cmake")
set(CMAKE_PREFIX_PATH ${QT5_PATH})

# components
find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

# enable cmake hearders in project tree
file(GLOB_RECURSE headers ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h )
source_group("Header Files" FILES ${headers})

qt5_wrap_cpp(
  MOC_FILES
   ./include/widget.h
 )

file(GLOB_RECURSE ui_files ${CMAKE_CURRENT_SOURCE_DIR}/ui/*.ui)
qt5_wrap_ui(UIC_FILES ${ui_files})
source_group("ui" FILES ${ui_files}) # ${UIC_FILES})

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src srcs)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(
  ${PROJECT_NAME}
  # WIN32
  ${MOC_FILES} 
  ${UIC_FILES}
  ${srcs}
  ${headers}
)

target_link_libraries(
  ${PROJECT_NAME} 
  PRIVATE 
  Qt5::Widgets 
  Qt5::Core 
  Qt5::Gui
)
