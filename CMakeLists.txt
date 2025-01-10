cmake_minimum_required(VERSION 3.31)

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

# Raylib
set(RAYLIB_INCLUDE_DIR "${EXTERN_DIR}/raylib/include")
set(RAYLIB_LIBRARY_DIR "${EXTERN_DIR}/raylib/lib")

include_directories(${RAYLIB_INCLUDE_DIR})
link_directories(${RAYLIB_LIBRARY_DIR})

# ImGui
set(IMGUI_DIR "${EXTERN_DIR}/imgui")
include_directories(${IMGUI_DIR} "${IMGUI_DIR}/backends")
set(RLIMGUI_DIR "${EXTERN_DIR}/rlImGui")
include_directories(${RLIMGUI_DIR})

set(RAYMGUI_SOURCES
    "${RLIMGUI_DIR}/rlImGui.cpp"
)

set(IMGUI_SOURCES
    "${IMGUI_DIR}/imgui.cpp"
    "${IMGUI_DIR}/imgui_demo.cpp"
    "${IMGUI_DIR}/imgui_draw.cpp"
    "${IMGUI_DIR}/imgui_widgets.cpp"
    "${IMGUI_DIR}/imgui_tables.cpp"
)

add_subdirectory(src)

add_executable(${PROJECT_NAME} "src/main.cpp" ${IMGUI_SOURCES} ${RAYMGUI_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib Application Engine Renderer)
