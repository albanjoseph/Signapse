cmake_minimum_required(VERSION 3.0)
project(Signapse)

add_subdirectory(src)
add_subdirectory(test)

set_target_properties(Signapse PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../bin/)
set_property(TARGET Signapse PROPERTY AUTOMOC ON)
add_compile_options(-Wall)

#allows google-tests to be called with ctest (not recommended as output will be less verbose, but in-case the user insists on using ctest)
enable_testing()

add_test(
        NAME test
        COMMAND ./test/main
)
