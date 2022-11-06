#include "operations.hpp"

#include <iostream>

std::ostream &operator<<(std::ostream &os, polynom p) {
    os << '[';
    for (int i = 0; i < p.coefs.size() - 1; ++i) {
        os << p.coefs[i] << ' ';
    }
    os << p.coefs.back() << ']';
    return os;
}

void add::perform(std::stack<polynom> &st) {
    polynom one = st.top();
    st.pop();
    polynom two = st.top();
    st.pop();
    // std::cout << one << " + " << two << std::endl;
    polynom &smaller_poly = one.coefs.size() < two.coefs.size() ? one : two;
    polynom &bigger_poly =
        std::addressof(smaller_poly) == std::addressof(one) ? two : one;
    for (uint32_t i = 0; i < smaller_poly.coefs.size(); ++i) {
        bigger_poly.coefs[i] += smaller_poly.coefs[i];
    }
    st.push(bigger_poly);
}

void subtract::perform(std::stack<polynom> &st) {
    polynom one = st.top();
    st.pop();
    polynom two = st.top();
    st.pop();
    // std::cout << one << " - " << two << std::endl;
    polynom &smaller_poly = one.coefs.size() < two.coefs.size() ? one : two;
    polynom &bigger_poly =
        std::addressof(smaller_poly) == std::addressof(one) ? two : one;
    for (uint32_t i = 0; i < smaller_poly.coefs.size(); ++i) {
        bigger_poly.coefs[i] -= smaller_poly.coefs[i];
    }
    st.push(bigger_poly);
}

void multiply::perform(std::stack<polynom> &st) {
    polynom one = st.top();
    st.pop();
    polynom two = st.top();
    st.pop();
    // std::cout << one << " * " << two << std::endl;
    polynom &smaller_poly = one.coefs.size() < two.coefs.size() ? one : two;
    polynom &bigger_poly =
        std::addressof(smaller_poly) == std::addressof(one) ? two : one;
    for (uint32_t i = 0; i < smaller_poly.coefs.size(); ++i) {
        bigger_poly.coefs[i] *= smaller_poly.coefs[i];
    }
    st.push(bigger_poly);
}

void derivative::perform(std::stack<polynom> &st) {
    polynom to_derive = st.top();
    st.pop();
    polynom res;
    if (to_derive.coefs.size() == 1) {
        res.coefs.push_back(0);
        st.push(res);
        return;
    }
    for (uint32_t cur_degree = 1; cur_degree < to_derive.coefs.size();
         ++cur_degree) {
        res.coefs.push_back(to_derive.coefs[cur_degree] * cur_degree);
    }
    st.push(res);
}

void integral::perform(std::stack<polynom> &st) {
    polynom to_integrate = st.top();
    st.pop();
    polynom res;
    for (uint32_t cur_degree = 0; cur_degree < to_integrate.coefs.size();
         ++cur_degree) {
        res.coefs.push_back(to_integrate.coefs[cur_degree] / (cur_degree + 1));
    }

    res.coefs.push_front(0);
    st.push(res);
}
