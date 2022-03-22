cmake_minimum_required(VERSION 3.10)

project(const)

add_executable(${PROJECT_NAME}
    "${PROJECT_NAME}.cc"
    "bank_account.cc"
)

include_directories("../common")
target_link_libraries(${PROJECT_NAME} common)

add_subdirectory(tests)

include(../CMake_common.txt)   # sets stdc++20, debug, etc