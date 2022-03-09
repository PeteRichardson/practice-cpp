cmake_minimum_required(VERSION 3.10)

project(collections)

add_executable(${PROJECT_NAME}
    "${PROJECT_NAME}.cc"
    "being.cc"
    "human.cc"
    "animal.cc"
)

include(../common/CMake_common.txt)   # sets stdc++20, debug, etc