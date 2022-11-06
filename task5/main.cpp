#include "l1_list.hpp"

#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
  std::ifstream fstr(argv[1]);
  l1_list l;
  int cur;
  do {
    fstr >> cur;
    if (fstr.eof()) {
      break;
    }
    l.add_node(cur);
  } while (true);

  l.print_list();

  l.delete_element(cur);

  l.print_list();

  return 0;
}
