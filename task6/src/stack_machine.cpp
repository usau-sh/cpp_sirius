#include "stack_machine.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

stack_machine::stack_machine(std::istream &is) {
    std::string full_line;
    std::getline(is, full_line);
    std::istringstream stream_to_parse;
    stream_to_parse.str(full_line);
    std::vector<std::string> lexems;
    for (std::string line; std::getline(stream_to_parse, line, ' ');) {
        lexems.push_back(line);
    }
    OperationFactory op_factory;
    for (auto cur = lexems.rbegin(); cur != lexems.rend(); ++cur) {
        if (is_polynom_start(cur)) {
            st.push(extract_polynom(cur));
        } else {
            op_factory.CreateObject(*cur)->perform(st);
        }
    }
}

bool stack_machine::is_polynom_start(
    std::reverse_iterator<std::vector<std::string>::iterator> i) {
    return i->back() == ']';
}

polynom stack_machine::extract_polynom(
    std::reverse_iterator<std::vector<std::string>::iterator> &i) {
    polynom res;
    // std::string cur = i->substr(0, i->length() - 1);
    // res.coefs.push_back(stoi(cur));
    // ++cur;
    std::string cur;
    for(; i -> front() != '['; ++i) {
        res.coefs.push_front(stoi(*i));
    }
    cur = i->substr(1);
    res.coefs.push_front(stoi(cur));
    return res;
}

polynom stack_machine::result() { return st.top(); }