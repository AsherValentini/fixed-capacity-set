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

