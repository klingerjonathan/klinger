project('loadsim', 'cpp')

thread_dep = dependency('threads')

inc_dir = include_directories('include')

src = ['src/loadsim.cpp', 'src/work_queue.cpp']

cc = meson.get_compiler('cpp')

executable('loadsim', 
            sources : src,
            include_directories : inc_dir,
            dependencies : thread_dep)


