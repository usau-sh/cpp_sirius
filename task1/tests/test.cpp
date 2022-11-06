#include <iostream>
#include "cassert"
#include "src1.h"

int main() {
    int a, b;
    std::cin >> a >> b;
    assert(sum(a, b) == a + b);
}