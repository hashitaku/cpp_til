cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 17)

project(glut_game CXX)

file(COPY "${CMAKE_SOURCE_DIR}/texture" DESTINATION "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

include_directories("${CMAKE_SOURCE_DIR}")

# cmake -DCMAKE_BUILD_TYPE=
set(CMAKE_CXX_FLAGS "-pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -g -fsanitize=address")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

add_subdirectory(src)
