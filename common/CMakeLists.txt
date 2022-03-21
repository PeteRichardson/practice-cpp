cmake_minimum_required(VERSION 3.10)

project(common)

add_library(${PROJECT_NAME} STATIC
    "common/log.cc"
    "common/person.cc"
)

target_link_libraries(${PROJECT_NAME} plog)

#add_subdirectory(tests)

include(../CMake_common.txt)   # sets stdc++20, debug, etc