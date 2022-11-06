#ifndef SRC1_H_
#define SRC1_H_
#include <iostream>
#include <vector>

struct Point {
  double X;
  double Y;
  friend std::istream& operator>>(std::istream& is, Point& pt);
  friend std::ostream& operator<<(std::ostream& is, Point& pt);
};

bool on_line_of_polygon(std::vector<Point> polygon, Point p);
bool point_in_polygon(std::vector<Point> p, Point point);

#endif