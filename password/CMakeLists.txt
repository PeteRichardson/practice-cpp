cmake_minimum_required(VERSION 3.10)

project(password)

set (CMAKE_BUILD_TYPE debug)

add_executable             (        password password.cc )
add_dependencies           (        password generate_wordlist tokenize_pdfs)
target_include_directories (        password PUBLIC "${PROJECT_BINARY_DIR}")
target_compile_features    (        password PUBLIC cxx_std_20)
if(APPLE)
add_custom_command(TARGET "${PROJECT_NAME}" POST_BUILD
    COMMAND dsymutil "${PROJECT_NAME}" 
    WORKING_DIRECTORY "${fileDirname}"
)
endif()

add_executable             (        generate_wordlist generate_wordlist.cc )
target_include_directories (        generate_wordlist PUBLIC "../common" "../plog/include")
target_compile_features    (        generate_wordlist PUBLIC cxx_std_20)
if(APPLE)
add_custom_command(TARGET generate_wordlist POST_BUILD
    COMMAND dsymutil generate_wordlist
    WORKING_DIRECTORY "${fileDirname}"
)
endif()

add_custom_target(tokenize_pdfs
    COMMAND generate_wordlist podofo.out | sort -u > words.h
    DEPENDS "${PROJECT_BINARY_DIR}/podofo.out"
    WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
)

add_custom_command(OUTPUT "${PROJECT_BINARY_DIR}/podofo.out"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND podofotxtextract hardin-tragedy.pdf > "${PROJECT_BINARY_DIR}/podofo.out" 2>/dev/null
    COMMAND podofotxtextract Origin_of_Species.pdf >> "${PROJECT_BINARY_DIR}/podofo.out" 2>/dev/null
    COMMAND podofotxtextract Music-Theory-Composition-Counterpoint.pdf >> "${PROJECT_BINARY_DIR}/podofo.out"  2>/dev/null 
)  


