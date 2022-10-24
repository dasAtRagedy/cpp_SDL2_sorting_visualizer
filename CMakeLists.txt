cmake_minimum_required(VERSION 3.23)
project(cpp_SDL2_sorting_visualizer)

set(CMAKE_CXX_STANDARD 23)

include_directories(additional_libraries/SDL2-2.24.1/include)
link_directories(additional_libraries/SDL2-2.24.1/lib/x86)

add_executable(cpp_SDL2_sorting_visualizer main.cpp)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
