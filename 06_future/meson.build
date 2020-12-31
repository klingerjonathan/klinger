project('06_future', 'cpp',
         default_options : ['cpp_std=c++2a', 'warning_level=3', 
                            'werror=true'])

incdir = include_directories('include')
src = ['src/main.cpp']
thread_dep = dependency('threads')

add_global_arguments('-I ~/workspace/builds/asio/asio/include/', language : 'cpp')
add_global_arguments('-DASIO_STANDALONE', language : 'cpp')
add_global_arguments('-DASIO_NO_DEPRECATED', language : 'cpp')

executable('factoring', 
            sources : src,
            include_directories : incdir,
            dependencies : thread_dep)