#ifndef POLYNOMS_HPP_
#define POLYNOMS_HPP_

#include <deque>
#include <cstdint>
#include <ostream>

struct polynom {
   std::deque<double> coefs;
};

std::ostream &operator<<(std::ostream &os, polynom p);

#endif