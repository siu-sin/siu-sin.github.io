cmake_minimum_required(VERSION 3.30)
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

set (MY_MAIN main)
set (MY_SRC 
	src/main.cpp
)
set (MY_LIB
	lib/hueta/hueta.cppm
	lib/isu/isu.cppm
)

project(MY_PROJECT)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD ON)

# Clang because of modules support
if (NOT CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message(FATAL_ERROR "Only Clang is supported")
endif()

#if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
#    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 18.1.2)
#        message(FATAL_ERROR "Clang version must be at least 18.1.2")
#    endif()
#else()
#    message(FATAL_ERROR "Only Clang is supported")
#endif()
#
add_executable(${MY_MAIN} ${MY_SRC} ${MY_LIB})
target_sources(main PUBLIC FILE_SET allModules TYPE CXX_MODULES FILES ${MY_LIB})
target_compile_options(${MY_MAIN} PRIVATE)
# compile options 
# cmake -B build -G Ninja && cmake --build build && ./build/main

# based on this
# https://www.reddit.com/r/cpp/comments/18rconj/comment/len1dgd/
