cmake_minimum_required(VERSION 3.10)

get_filename_component(project_dir ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${project_dir})

add_executable(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}.cc ../common/utils.cc ../common/person.cc)
target_compile_features(${CMAKE_PROJECT_NAME} PUBLIC cxx_std_20)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
                           "${PROJECT_DIR}../common"
                           )
                           
SET(COMPILE_LAYOUT_FLAGS "-Wpadded")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${COMPILE_LAYOUT_FLAGS}")

add_custom_command(TARGET "${CMAKE_PROJECT_NAME}" POST_BUILD
    COMMAND dsymutil "${CMAKE_PROJECT_NAME}" 
    WORKING_DIRECTORY "${fileDirname}"
)
