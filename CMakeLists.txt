cmake_minimum_required(VERSION 3.10)

project(cpp)

include(FetchContent)
FetchContent_Declare(
    cpp-terminal
    GIT_REPOSITORY https://github.com/jupyter-xeus/cpp-terminal.git
    GIT_TAG        d22ea37b16663906f437a6193c81607eca3ce30d
)

FetchContent_MakeAvailable(cpp-terminal)


add_subdirectory(common)
add_subdirectory(plog)
add_subdirectory(async)
add_subdirectory(bitwise)
add_subdirectory(classes)
add_subdirectory(collections)
add_subdirectory(const)
add_subdirectory(customliterals)
add_subdirectory(files)
add_subdirectory(format)
add_subdirectory(hash)
add_subdirectory(hex)
add_subdirectory(intsize)
add_subdirectory(literals)
add_subdirectory(logtest)
add_subdirectory(move)
add_subdirectory(opt)
add_subdirectory(password)
add_subdirectory(person)
add_subdirectory(rvaltest)
add_subdirectory(streaming)
add_subdirectory(strings)
add_subdirectory(templ)
add_subdirectory(term)
add_subdirectory(time)
add_subdirectory(virt)



