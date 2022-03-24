cmake_minimum_required(VERSION 3.10)

project(password)

add_executable             (        password password.cc words.h)
add_dependencies           (        password generate_wordlist)
target_include_directories (        password PUBLIC "${PROJECT_BINARY_DIR}")
target_compile_features    (        password PUBLIC cxx_std_20)
get_target_property(target_type ${PROJECT_NAME} TYPE)
if(APPLE)
    if("${CMAKE_GENERATOR}" STREQUAL "Xcode")
        set_target_properties(password PROPERTIES XCODE_ATTRIBUTE_DEBUG_INFORMATION_FORMAT "dwarf-with-dsym")
    else()
        add_custom_command(TARGET password POST_BUILD
            COMMAND dsymutil password 
            WORKING_DIRECTORY "${fileDirname}"
        )
    endif()
endif()


add_executable             (        generate_wordlist generate_wordlist.cc)
target_include_directories (        generate_wordlist PUBLIC "../common")
target_link_libraries      (        generate_wordlist common)
target_compile_features    (        generate_wordlist PUBLIC cxx_std_20)
if(APPLE)
    if("${CMAKE_GENERATOR}" STREQUAL "Xcode")
        set_target_properties(generate_wordlist PROPERTIES XCODE_ATTRIBUTE_DEBUG_INFORMATION_FORMAT "dwarf-with-dsym")
    else()
        add_custom_command(TARGET generate_wordlist POST_BUILD
            COMMAND dsymutil generate_wordlist 
            WORKING_DIRECTORY "${fileDirname}"
        )
    endif()
endif()

add_custom_command(OUTPUT words.h
    COMMAND generate_wordlist podofo.out | sort -u > words.h
    DEPENDS "${PROJECT_BINARY_DIR}/podofo.out"
    WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
)

add_custom_command(OUTPUT "${PROJECT_BINARY_DIR}/podofo.out"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND podofotxtextract hardin-tragedy.pdf > "${PROJECT_BINARY_DIR}/podofo.out" 2>/dev/null
    COMMAND podofotxtextract Origin_of_Species.pdf >> "${PROJECT_BINARY_DIR}/podofo.out" 2>/dev/null
    COMMAND podofotxtextract Music-Theory-Composition-Counterpoint.pdf >> "${PROJECT_BINARY_DIR}/podofo.out" 2>/dev/null
    DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/hardin-tragedy.pdf"
    DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/Origin_of_Species.pdf"
    DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}//Music-Theory-Composition-Counterpoint.pdf"
)  


