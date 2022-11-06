project(l1_list)

include_directories(include)

file(GLOB SOURCES src/*.cpp)
add_library(l1_list ${SOURCES})

add_executable(list_test main.cpp)
target_link_libraries(list_test l1_list)