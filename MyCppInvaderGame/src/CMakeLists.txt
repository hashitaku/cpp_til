cmake_minimum_required(VERSION 3.10)

add_executable(MyInvaderGame
    main.cpp
    system.cpp
    draw.cpp
    stb_image.cpp
)

target_include_directories(MyInvaderGame PUBLIC 
	"${PROJECT_SOURCE_DIR}/include"
	"${PROJECT_SOURCE_DIR}/thirdparty/freeglut/include"
)

target_compile_features(MyInvaderGame PUBLIC cxx_std_17)

target_compile_options(MyInvaderGame PUBLIC
	$<$<CXX_COMPILER_ID:MSVC>:
    	$<$<CONFIG:Debug>:/std:c++17 /W4>
    	$<$<CONFIG:Release>:/O2>
    >

    $<$<CXX_COMPILER_ID:GCC>:
    	$<$<CONFIG:Debug>:-pedantic -Wall -Wextra -g3 -fsanitize=undefined>
    	$<$<CONFIG:Release>:-pedantic -O3 -DNDEBUG>
    >

    $<$<CXX_COMPILER_ID:Clang>:
    	$<$<CONFIG:Debug>:-pedantic -Wall -Wextra -g3 -fsanitize=undefined?>
    	$<$<CONFIG:Release>:-pedantic -O3 -DNDEBUG>
    >
)

target_link_libraries(MyInvaderGame PUBLIC
    "$<$<PLATFORM_ID:Windows>:OpenGL32 freeglut_static>"
    "$<$<PLATFORM_ID:Linux>:GL;X11;Xxf86vm;Xrandr;Xi;freeglut_static>"
)
