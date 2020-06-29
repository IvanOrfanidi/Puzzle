# Version CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(puzzle)

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
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  add_compile_options(/W4 /WX)
endif()

# Find Qt5
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

# Source files
file(GLOB_RECURSE SOURCES 
  src/*.cpp
  include/*.h)

# Compiling target
add_executable(${PROJECT_NAME} ${SOURCES})

# Link target
target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
target_link_libraries(${PROJECT_NAME})
