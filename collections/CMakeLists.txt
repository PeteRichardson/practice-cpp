cmake_minimum_required(VERSION 3.10)

get_filename_component(project_dir ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${project_dir})

add_executable(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}.cc being.cc human.cc animal.cc)
target_compile_features(${CMAKE_PROJECT_NAME} PUBLIC cxx_std_20)

add_custom_command(TARGET "${CMAKE_PROJECT_NAME}" POST_BUILD
    COMMAND dsymutil "${CMAKE_PROJECT_NAME}" 
    WORKING_DIRECTORY "${fileDirname}"
)
