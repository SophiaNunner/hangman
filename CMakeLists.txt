cmake_minimum_required(VERSION 3.0.0)
project(Hangman VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)

include_directories(main)

add_subdirectory(main)
option(BUILD_TESTS "Build all tests." ON)
if(BUILD_TESTS)
    add_subdirectory(test)
    add_subdirectory(lib/googletest)
endif()