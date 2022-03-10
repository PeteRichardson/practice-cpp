cmake_minimum_required(VERSION 3.10)

project(customliterals)

add_executable(${PROJECT_NAME}
    "${PROJECT_NAME}.cc"
    "../common/person.cc"
    "../common/log.cc"
)

include_directories("../common" "../plog/include")

include(../common/CMake_common.txt)   # sets stdc++20, debug, etc