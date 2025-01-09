cmake_minimum_required(VERSION 3.1)

# set project name and version
project(qlexEngine VERSION 0.1.0 LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Var
set(EXTERN_DIR "${CMAKE_SOURCE_DIR}/extern")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

# Include headers
include_directories(${INCLUDE_DIR})

# Include Raylib
set(RAYLIB_INCLUDE_DIR "${EXTERN_DIR}/raylib/include")
set(RAYLIB_LIBRARY_DIR "${EXTERN_DIR}/raylib/lib")

include_directories(${RAYLIB_INCLUDE_DIR})
link_directories(${RAYLIB_LIBRARY_DIR})

add_subdirectory(src)

add_executable(qlexEngine "src/main.cpp")

target_include_directories(qlexEngine PUBLIC ${PROJECT_BINARY_DIR})
target_link_libraries(qlexEngine PRIVATE raylib Application Engine Renderer)
