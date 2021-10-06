cmake_minimum_required(VERSION 3.16)

project(pracc_net CXX)

find_package(Boost REQUIRED COMPONENTS system)
find_package(Threads REQUIRED)

add_subdirectory(src)
