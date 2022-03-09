cmake_minimum_required(VERSION 3.10)

project(virt)

add_executable(${PROJECT_NAME}
    "${PROJECT_NAME}.cc"
)

include(../common/CMake_common.txt)   # sets stdc++20, debug, etc