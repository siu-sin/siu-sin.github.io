cmake_minimum_required(VERSION 3.30)
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

set (MY_MAIN main)
set (MY_SRC 
	src/main.cpp
)
set (MY_LIB
	lib/hueta/CarFactory.h
	lib/isu/Logger.cpp
)

include_directories("${CMAKE_SOURCE_DIR}/lib/hueta"
	"${CMAKE_SOURCE_DIR}/lib/isu"
)

project(MY_PROJECT)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD ON)

add_executable(${MY_MAIN} ${MY_SRC} ${MY_LIB})
target_compile_options(${MY_MAIN} PRIVATE)

# compile options 
# cmake -B build -G Ninja && cmake --build build && ./build/main

# based on this
# https://www.reddit.com/r/cpp/comments/18rconj/comment/len1dgd/

# Completely removed the module thing
