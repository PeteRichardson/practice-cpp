cmake_minimum_required(VERSION 3.10)

project(person)

add_executable(${PROJECT_NAME}
    "${PROJECT_NAME}.cc"
    "../common/person.cc"
)

include_directories("../common")

include(../common/CMake_common.txt)   # sets stdc++20, debug, etc