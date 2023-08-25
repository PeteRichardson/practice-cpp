cmake_minimum_required(VERSION 3.10)

project(iterators)

add_executable(${PROJECT_NAME}
    "${PROJECT_NAME}.cc"
)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt-header-only)

include(../CMake_common.txt)   # sets stdc++20, debug, etc