cmake_minimum_required(VERSION 3.10)

project(password)

set (CMAKE_BUILD_TYPE debug)

add_executable             (        password password.cc )
add_dependencies           (        password generate_wordlist tokenize_pdfs)
target_compile_features    (        password PUBLIC cxx_std_20)
add_custom_command         ( TARGET password POST_BUILD
    COMMAND dsymutil "password" 
    WORKING_DIRECTORY "${fileDirname}"
)

add_executable             (        generate_wordlist generate_wordlist.cc )
target_include_directories (        generate_wordlist PUBLIC "../common" "../plog/include")
target_compile_features    (        generate_wordlist PUBLIC cxx_std_20)
add_custom_command         ( TARGET generate_wordlist POST_BUILD
    COMMAND dsymutil "generate_wordlist" 
    WORKING_DIRECTORY "${fileDirname}"
)

set(PDF_DIR "..")

add_custom_target(tokenize_pdfs
    COMMAND generate_wordlist podofo.out | sort -u > words.h
    DEPENDS podofo.out
    WORKING_DIRECTORY "${fileDirname}"
)

add_custom_command(OUTPUT podofo.out 
    COMMAND podofotxtextract "${PDF_DIR}/hardin-tragedy.pdf" > podofo.out 2>/dev/null
    COMMAND podofotxtextract "${PDF_DIR}/Origin_of_Species.pdf" >> podofo.out 2>/dev/null
    COMMAND podofotxtextract "${PDF_DIR}/Music-Theory-Composition-Counterpoint.pdf" >> podofo.out  2>/dev/null
)  


