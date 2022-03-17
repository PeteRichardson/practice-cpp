cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_executable( common_tests
    person_tests.cc
    "../common/person.cc"
)

target_link_libraries( common_tests
    gtest_main
    plog
)

include(GoogleTest)
gtest_discover_tests( common_tests )