project(polynom_calculator)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")
add_library(stack_machine ${SOURCES})

add_executable(polynom_calculator main.cpp)
target_link_libraries(polynom_calculator stack_machine)