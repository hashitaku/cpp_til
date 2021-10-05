project('pracc_cpp', 'cpp', default_options : [
    'warning_level=3',
    'cpp_std=c++2a',
    'werror=true',
    ]
)

boost = dependency('boost', modules : ['system'])
threads = dependency('threads')

subdir('src')
