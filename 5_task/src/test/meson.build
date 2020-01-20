gtest = dependency('gtest', main: true)
test(
    'merge_sort',
    executable(
        'merge_sort_test',
        sources: ['merge_sort_test.cc'],
        include_directories: src,
        dependencies: [gtest]
    )
)
