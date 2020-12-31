project('06_future', 'cpp',
         default_options : ['cpp_std=c++17', 'warning_level=0', 
                            'werror=true'])

incdir = include_directories('include')
src = ['src/main.cpp']
thread_dep = dependency('threads')

executable('factoring', 
            sources : src,
            include_directories : incdir,
            dependencies : thread_dep)