cmake_minimum_required(VERSION 3.10)

project(files)

add_executable(${PROJECT_NAME}
    "${PROJECT_NAME}.cc"
    "readers.cc"
)

include_directories("../common")

include(../CMake_common.txt)   # sets stdc++20, debug, etc