cmake_minimum_required(VERSION 3.10)

project(common)

add_library(${PROJECT_NAME} STATIC
    "common/log.cc"
    "common/person.cc"
)

include_directories(
    "../plog/include"
    )

include(../CMake_common.txt)   # sets stdc++20, debug, etc