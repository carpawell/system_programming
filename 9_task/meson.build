project (
    'myproject',
    'cpp',
    version: '0.1.0',
    meson_version: '>=0,46',
    default_options: ['cpp_std=c++11']
)
subdir('src')

doxyfile = configuration_data()
doxyfile.set('OUTPUT_DIRECTORY', meson.build_root())
doxyfile.set('EXTRACT_ALL', 'YES')
input_files = [join_paths(meson.source_root(), 'src', 'myproject', '5_task'),]
doxyfile.set('INPUT', ' '.join(input_files))
configure_file(input: 'Doxyfile.in', output: 'Doxyfile', configuration: doxyfile)
doxygen = find_program('doxygen')
if doxygen.found()
    run_target('doc', command: [doxygen,
        join_paths(meson.build_root(), 'Doxyfile')])
endif