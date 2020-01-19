gtest = dependency('gtest', main: true)

test(
    'where',
    executable(
        'where_test',
        sources: ['where_test.cpp'],
        include_directories: src,
        dependencies: [gtest]
    )
)

test(
    'isSymmetric',
    executable(
	'is_symmetric_test',
	sources: ['is_symmetric_test.cpp'],
	include_directories: src,
	dependencies: [gtest]
    )
)
