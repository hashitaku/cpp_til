add_executable(pracc_net
    main.cpp
)

target_compile_features(pracc_net PUBLIC cxx_std_20)

target_compile_options(pracc_net PUBLIC
    $<$<CXX_COMPILER_ID:GCC>:
    	$<$<CONFIG:Debug>:-pedantic -Wall -Wextra -g3 -fsanitize=undefined>
    	$<$<CONFIG:Release>:-pedantic -O3 -DNDEBUG>
    >
)

target_link_libraries(pracc_net PUBLIC
    Boost::system
    Threads::Threads
)
