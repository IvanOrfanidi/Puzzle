# Version CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(puzzle)

# Options
set(CMAKE_CXX_STANDARD 17)

# Compiler-specific options
add_compile_options(
    -Wall
    -Werror
    -Wextra
    -Wpedantic
)

# Find Qt5
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

file(GLOB_RECURSE SOURCES
    source/*.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
)
