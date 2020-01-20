gtest = dependency('gtest', main: true)
test(
    'Geometry',
    executable(
        'Geometry_test',
        sources: ['Geometry_test.cc'],
        include_directories: src,
        dependencies: [gtest]
    )
)
test(
    'Polynomial',
    executable(
        'Polynomial_test',
        sources: ['Polynomial_test.cc'],
        include_directories: src,
        dependencies: [gtest]
    )
)
