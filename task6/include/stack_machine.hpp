#ifndef STACK_MACHINE_HPP_
#define STACK_MACHINE_HPP_

#include "op_factory.hpp"
#include "polynom.hpp"
#include <fstream>
#include <stack>

class stack_machine {
  private:
    std::stack<polynom> st;
    bool is_polynom_start(
        std::reverse_iterator<std::vector<std::string>::iterator> i);
    polynom extract_polynom(
        std::reverse_iterator<std::vector<std::string>::iterator> &i);
    
  public:
    stack_machine(std::istream &is);
    polynom result();
};

#endif