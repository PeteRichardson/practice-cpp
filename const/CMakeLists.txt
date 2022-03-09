cmake_minimum_required(VERSION 3.10)

project(const)

add_executable(${PROJECT_NAME}
    "${PROJECT_NAME}.cc"
    "bank_account.cc"
)

include(../common/CMake_common.txt)   # sets stdc++20, debug, etc