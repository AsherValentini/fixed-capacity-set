cmake_minimum_required(VERSION 3.24)
project(fixed-capacity-set)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(core INTERFACE)
target_include_directories(core 
	INTERFACE
		${CMAKE_SOURCE_DIR}/include
) 

add_executable(prog
	src/main.cpp
) 

target_link_libraries(prog 
	PRIVATE
		core
) 

# Google Test Library
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

# Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Google Test Execs
add_executable(set_tests
    tests/set_tests.cpp
)
target_link_libraries(set_tests
    PRIVATE
        core
        GTest::gtest
        GTest::gtest_main
)
add_test(NAME set_tests COMMAND set_tests)