project('06_future', 'cpp')

inc_dir = include_directories('include')

src = ['src/main.cpp']

thread_dep = dependency('threads')

executable('factoring', 
            sources : src,
            include_directories : inc_dir,
            dependencies : thread_dep)