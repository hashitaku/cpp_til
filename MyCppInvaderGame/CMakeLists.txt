cmake_minimum_required(VERSION 3.10)

project(glut_game CXX)

file(COPY "${CMAKE_SOURCE_DIR}/texture" DESTINATION "${CMAKE_BINARY_DIR}/out")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out")

add_subdirectory(thirdparty/freeglut)
add_subdirectory(src)
