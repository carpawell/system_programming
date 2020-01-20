myproject_src = files([
    'main.cpp'
])

python = dependency('python')
threads = dependency('threads')

executable(
    'myproject',
    include_directories: src,
    sources: myproject_src,
    dependencies: [python,threads],
    install: true,
)
