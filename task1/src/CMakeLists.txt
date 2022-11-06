add_library(my_lib src1.cpp)
add_executable(main_exe main.cpp)
target_link_libraries(main_exe my_lib)