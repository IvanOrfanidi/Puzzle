# Version CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(puzzle VERSION 1.0.3)

configure_file(
    project_version.h.in ${CMAKE_CURRENT_BINARY_DIR}/project_version.h
)

# Options
set(CMAKE_CXX_STANDARD 17)

# Compiler-specific options
if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
    add_compile_options(
        -Werror
        -pedantic-errors
        
        -Wall
        -Wextra
        -Wpedantic

        -Wcast-align
        -Wcast-qual
        -Wconversion
        -Wextra-semi
        -Wenum-compare
        -Wfloat-equal
        -Wnon-virtual-dtor
        -Woverloaded-virtual
        -Wredundant-decls
        -Wold-style-cast
        -Wsign-promo
        -Wzero-as-null-pointer-constant
        -Wsign-conversion
    )
endif()

# Find Qt5
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

# Source files
file(GLOB_RECURSE SOURCES 
    source/*.cpp
)

# Compiling target
add_executable(${PROJECT_NAME} ${SOURCES})

# For path '<...>'
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Set build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

# For path to project_version.h
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link target
target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
)
