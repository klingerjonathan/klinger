project('05_sync3', 'cpp')

hread_dep = dependency('threads')

inc_dir = include_directories(['include'])

src = ['src/main.cpp', 'src/Philosopher.cpp', 'src/semaphore.cpp']

executable('dining',
            sources : src,
            include_directories : inc_dir)