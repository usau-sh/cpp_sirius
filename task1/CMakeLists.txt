include_directories(src)
add_subdirectory(src)

file(GLOB TEST_SRCS tests/*.cpp)
add_executable(tests ${TEST_SRCS})
target_link_libraries(tests my_lib)