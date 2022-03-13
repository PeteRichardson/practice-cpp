cmake_minimum_required(VERSION 3.10)

project(format)

add_executable(${PROJECT_NAME}
    "${PROJECT_NAME}.cc"
)

include(../CMake_common.txt)   # sets stdc++20, debug, etc