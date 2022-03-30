cmake_minimum_required(VERSION 3.10)

project(accumulate)

add_executable(${PROJECT_NAME}
    "${PROJECT_NAME}.cc"
)

# include_directories("../common")
# target_link_libraries(${PROJECT_NAME} common ncurses)
# add_compile_options("-Wpadded")

include(../CMake_common.txt)   # sets stdc++20, debug, etc