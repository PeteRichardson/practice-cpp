cmake_minimum_required(VERSION 3.28)

project(cpp)

set(CMAKE_INSTALL_PREFIX "/Users/pete/bin2")
option(CPPTERMINAL_ENABLE_TESING "Skip cpp-terminal test code" OFF)
option(CMAKE_VERBOSE_MAKEFILE "Show commands while building" ON)

include(FetchContent)
FetchContent_Declare(
    cpp-terminal
    GIT_REPOSITORY https://github.com/jupyter-xeus/cpp-terminal.git
    GIT_TAG        cafdfac96aec894ec101d4298bee5c1c616615e3
)
FetchContent_Declare(
    plog
    GIT_REPOSITORY https://github.com/SergiusTheBest/plog.git
    GIT_TAG        1.1.10
    )
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG        v1.14.0
)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG        10.2.1
)

FetchContent_MakeAvailable(cpp-terminal)
FetchContent_MakeAvailable(plog)
FetchContent_MakeAvailable(googletest)
FetchContent_MakeAvailable(fmt)

enable_testing()

add_subdirectory(accumulate)
add_subdirectory(common)
add_subdirectory(async)
add_subdirectory(bitwise)
add_subdirectory(byte)
add_subdirectory(classes)
add_subdirectory(collections)
add_subdirectory(const)
add_subdirectory(customliterals)
add_subdirectory(files)
add_subdirectory(format)
add_subdirectory(hash)
add_subdirectory(hex)
add_subdirectory(intsize)
add_subdirectory(iterators)
add_subdirectory(lambdas)
add_subdirectory(linkedlist)
add_subdirectory(literals)
add_subdirectory(logtest)
add_subdirectory(move)
add_subdirectory(opt)
add_subdirectory(password)
add_subdirectory(person)
add_subdirectory(rvaltest)
add_subdirectory(streaming)
add_subdirectory(strings)
add_subdirectory(strlen)
add_subdirectory(templ)
add_subdirectory(term)
add_subdirectory(time)
if(NOT APPLE)
    add_subdirectory(views)   # Views won't compile with clang
endif()
add_subdirectory(virt)



