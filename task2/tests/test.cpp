#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include "cassert"
#include "src1.h"

int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cout << "too few arguments" << std::endl;
    return 1;
  }
  std::cout << argv[1] << ' ' << argv[2] << ' ' << argv[3] << std::endl;
  std::ifstream file(argv[1]);
  std::vector<Point> polygon(std::istream_iterator<Point>(file), {});
  double x = strtod(argv[2], nullptr);
  double y = strtod(argv[3], nullptr);
  Point pt{x, y};
  if (on_line_of_polygon(polygon, pt)) {
    std::cout << "The point" << pt << " is on the edge of the poly";
  } else if (point_in_polygon(polygon, pt)) {
    std::cout << "The point " << pt << " is inside the polygon";
  } else {
    std::cout << "The point " << pt << " is outside of the polygon";
  }
}