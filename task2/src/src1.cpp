#include "src1.h"

#include <cmath>

bool point_on_line(Point a, Point b, Point p) {
  double px = a.X - b.X;
  double py = a.Y - b.Y;
  double norm = px * px + py * py;
  double u = ((p.X - b.X) * px + (p.Y - b.Y) * py) / norm;
  if (u > 1) {
    u = 1;
  } else if (u < 0) {
    u = 0;
  }
  double x = b.X + u * px;
  double y = b.Y + u * py;
  double dx = x - p.X;
  double dy = y - p.Y;

  return (dx * dx + dy * dy) == 0;
}

bool on_line_of_polygon(std::vector<Point> polygon, Point p) {
  for (int i = 1; i < polygon.size(); ++i) {
    // std::cout << polygon[i]  << ' ' << polygon[i - 1] << std::endl;
    if (point_on_line(polygon[i - 1], polygon[i], p)) {
      return true;
    }
  }
  // std::cout << polygon.back() << ' ' << polygon.front() << std::endl;
  return point_on_line(polygon.back(), polygon.front(), p);
}

bool point_in_polygon(std::vector<Point> p, Point point) {
  bool result = false;
  int j = p.size() - 1;
  for (int i = 0; i < p.size(); i++) {
    if ((p[i].Y < point.Y && p[j].Y >= point.Y ||
         p[j].Y < point.Y && p[i].Y >= point.Y) &&
        (p[i].X + (point.Y - p[i].Y) / (p[j].Y - p[i].Y) * (p[j].X - p[i].X) <
         point.X))
      result = !result;
    j = i;
  }
  return result;
}

std::istream& operator>>(std::istream& is, Point& pt) {
  is >> pt.X >> pt.Y;
  return is;
}

std::ostream& operator<<(std::ostream& is, Point& pt) {
  is << '(' << pt.X << ',' << pt.Y << ')';
  return is;
}