include_directories(src)
add_subdirectory(src)

file(GLOB TEST_SRCS tests/*.cpp)
add_executable(robot ${TEST_SRCS})
target_link_libraries(robot my_lib)