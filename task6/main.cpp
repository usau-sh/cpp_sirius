#include "stack_machine.hpp"

#include <iostream>

int main() {
    std::cout << "Please enter your expression" << std::endl;
    stack_machine st(std::cin);
    std::cout << st.result() << std::endl;
}