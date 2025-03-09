cmake_minimum_required(VERSION 3.31.6)
project(cpp-rlib-conwaygameoflife VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(raylib CONFIG REQUIRED)

include_directories(src)
add_executable(cpp-rlib-conwaygameoflife 
    src/main.cpp 
    src/grid.cpp
    src/simulation.cpp
)
target_link_libraries(cpp-rlib-conwaygameoflife PRIVATE raylib)
