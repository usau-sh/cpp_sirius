#ifndef OPERRATIONS_HPP
#define OPERRATIONS_HPP

#include "polynom.hpp"
#include <cstdint>
#include <stack>

class operation {
  public:
    virtual void perform(std::stack<polynom> &st) = 0;
    virtual ~operation(){};
};

class add : public operation {
  public:
    void perform(std::stack<polynom> &st) override;
};

class subtract : public operation {
  public:
    void perform(std::stack<polynom> &st) override;
};

class multiply : public operation {
  public:
    void perform(std::stack<polynom> &st) override;
};

class derivative : public operation {
  public:
    void perform(std::stack<polynom> &st) override;
};

class integral : public operation {
  public:
    void perform(std::stack<polynom> &st) override;
};

#endif