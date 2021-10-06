project('test_gl', 'c', 'cpp',
    version: '1.0',
    license: 'MIT',
    default_options: [
    'warning_level=3',
    'c_std=c11',
    'cpp_std=c++2a',
    'b_sanitize=undefined',
    ],
)

cmake = import('cmake')
glfw3_cmake_options = cmake.subproject_options()
glfw3_cmake_options.add_cmake_defines(
    {'GLFW_BUILD_EXAMPLES': 'OFF'},
    {'GLFW_BUILD_TESTS': 'OFF'},
    {'GLFW_INSTALL': 'OFF'}
)
glfw3_subproj = cmake.subproject('glfw3', options: glfw3_cmake_options)
glfw3 = glfw3_subproj.dependency('glfw')

glew = dependency('glew',
    default_options: [
        'default_library=static',
        'warning_level=0',
    ]
)
gl = dependency('gl')
x11 = dependency('x11')
threads = dependency('threads')

cc = meson.get_compiler('c')
m = cc.find_library('m')
rt = cc.find_library('rt')
dl = cc.find_library('dl')

includes = include_directories('include')
src = files(
    'src/main.cpp'
)

executable('test_gl',
    src,
    include_directories: includes,
    dependencies: [glew, glfw3, gl, x11, threads, m, rt, dl]
)
