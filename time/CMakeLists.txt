cmake_minimum_required(VERSION 3.10)

project(time)

add_executable(${PROJECT_NAME}
    "${PROJECT_NAME}.cc"
)

include_directories("../common")

include(../CMake_common.txt)   # sets stdc++20, debug, etc