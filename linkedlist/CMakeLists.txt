cmake_minimum_required(VERSION 3.18)

project(llapp)

add_executable(${PROJECT_NAME} 
    ${PROJECT_NAME}.cpp
    LinkedList.cpp
    Node.cpp
)

include_directories("../common")

include(../CMake_common.txt)   # sets stdc++20, debug, etc