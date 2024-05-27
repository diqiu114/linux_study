cmake_minimum_required(VERSION 3.0)

project(run_me)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
add_executable(run_me main.c)
