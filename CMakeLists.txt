# Version CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(puzzle VERSION 1.0.3)

configure_file(
    project_version.h.in ${CMAKE_CURRENT_BINARY_DIR}/project_version.h
)

# Option
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

# Compiler-specific options
if((CMAKE_CXX_COMPILER_ID MATCHES "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
    add_compile_options(
        -Werror

        -Wall
        -Wextra
        -Wpedantic

        -Wcast-align
        -Wcast-qual
        -Wenum-compare
        -Wfloat-equal
        -Wnon-virtual-dtor
        -Woverloaded-virtual
        -Wredundant-decls
        -Wsign-promo
    )
endif()

# Find Qt5
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

# Source files
file(GLOB_RECURSE SOURCES 
    src/*.cpp
    include/*.h
)

# Compiling target
add_executable(${PROJECT_NAME} ${SOURCES})

# For path '<...>'
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# For path to project_version.h
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link target
target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
target_link_libraries(${PROJECT_NAME})
