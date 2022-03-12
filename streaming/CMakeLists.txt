cmake_minimum_required(VERSION 3.10)

project(streaming)

add_executable(${PROJECT_NAME}
    "${PROJECT_NAME}.cc"
    "../common/person.cc"
    "../common/log.cc"
)

include_directories("../common" "../plog/include")
# add_compile_options("-Wpadded")
# target_link_libraries(${PROJECT_NAME} -lncurses)

set (CMAKE_BUILD_TYPE debug)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
add_custom_command(TARGET "${PROJECT_NAME}" POST_BUILD
    COMMAND dsymutil "${PROJECT_NAME}" 
    WORKING_DIRECTORY "${fileDirname}"
)