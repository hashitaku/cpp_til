cmake_minimum_required(VERSION 3.10)

add_executable(MyInvaderGame.out
    main.cpp
    system.cpp
    draw.cpp
    stb_image.cpp
)

target_include_directories(MyInvaderGame.out PUBLIC "${PROJECT_SOURCE_DIR}/include")

target_compile_features(MyInvaderGame.out PUBLIC cxx_std_17)

target_compile_options(MyInvaderGame.out PUBLIC
    $<$<CONFIG:Debug>:-pedantic -Wall -Wextra -g3 -fsanitize=undefined>
    $<$<CONFIG:Release>:-pedantic -O3 -DNDEBUG>
)

target_link_libraries(MyInvaderGame.out PUBLIC
    GL
    X11
    Xxf86vm
    Xrandr
    Xi
    freeglut_static
)
