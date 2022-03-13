cmake_minimum_required(VERSION 3.10)

project(common)

add_library(${PROJECT_NAME}
    "common/log.cc"
    "common/person.cc"
)

include_directories(
    "../plog/include"
    )
