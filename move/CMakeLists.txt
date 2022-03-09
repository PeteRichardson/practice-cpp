cmake_minimum_required(VERSION 3.10)

project(move)

add_executable(${PROJECT_NAME}
    "${PROJECT_NAME}.cc"
)

include_directories("../common")
add_compile_options("-Wpadded")

include(../common/CMake_common.txt)   # sets stdc++20, debug, etc