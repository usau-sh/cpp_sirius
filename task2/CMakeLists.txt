include_directories(src)
add_subdirectory(src)

file(GLOB TEST_SRCS tests/*.cpp)
add_executable(is_point_inside_poly ${TEST_SRCS})
target_link_libraries(is_point_inside_poly my_lib)