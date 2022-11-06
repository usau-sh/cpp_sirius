#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include "cassert"
#include "src1.h"

int main(int argc, char* argv[]) {
  if (argc < 4) {
    std::cout << "too few arguments" << std::endl;
    return 1;
  }
  std::cout << argv[1] << ' ' << argv[2] << ' ' << argv[3] << ' ' << argv[4]
            << std::endl;
  std::ifstream file(argv[1]);
  std::vector<Actions> act_vector(std::istream_iterator<Actions>(file), {});
  Coords start_coords{strtol(argv[2], nullptr, 10),
                      strtol(argv[3], nullptr, 10)};
  Orientations orient = strtoorient(argv[4]);
  Robot r(orient, start_coords);
  r.run_actions(act_vector);
  std::cout << "Final position: " << r.get_coords();
  std::cout << "Final orientation: " << r.get_orientation();
}