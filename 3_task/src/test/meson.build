gtest = dependency('gtest', main: true)
test(
    'MyMessage',
    executable(
        'MyMessage_test',
        sources: ['MyMessage_test.cc'],
        include_directories: src,
        dependencies: [gtest]
    )
)
test(
    'MyCat',
    executable(
        'MyCat_test',
        sources: ['MyCat_test.cc'],
        include_directories: src,
        dependencies: [gtest]
    )
)
test(
    'MyTie',
    executable(
        'MyTie_test',
        sources: ['MyTie_test.cc'],
        include_directories: src,
        dependencies: [gtest]
    )
)