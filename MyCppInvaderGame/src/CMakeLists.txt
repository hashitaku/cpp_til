cmake_minimum_required(VERSION 3.10)

add_executable(MyInvaderGame.out
    main.cpp
    system.cpp
)

target_link_libraries(MyInvaderGame.out -lGL -lglut)
