cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_executable( const_test
    bankaccount_tests.cc
    ../bank_account.cc
)

target_link_libraries( const_test
    gtest_main
    plog
)

include(GoogleTest)
gtest_discover_tests(const_test)