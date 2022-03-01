add_executable(taskmaster_test taskmaster_test.cpp)
target_include_directories(taskmaster_test PRIVATE ../src)
target_link_libraries(taskmaster_test taskmaster)
