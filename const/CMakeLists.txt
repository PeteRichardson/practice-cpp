cmake_minimum_required(VERSION 3.10)

project(const)

add_executable(${PROJECT_NAME}
    "${PROJECT_NAME}.cc"
    "bank_account.cc"
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)
add_custom_command(TARGET "${PROJECT_NAME}" POST_BUILD
    COMMAND dsymutil "${PROJECT_NAME}" 
    WORKING_DIRECTORY "${fileDirname}"
)