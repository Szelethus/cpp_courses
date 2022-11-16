#include <iostream>

struct Point {
  int x;
  int y;
};

std::ostream &operator<<(std::ostream &out, Point p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

struct LessByX {
  bool operator()(Point a, Point b) {
    return a.x < b.x;
  }
};

bool operator==(Point a, Point b) {
  return a.x == b.x && a.y == b.y;
}

using set_iter = std::set<Point>::iterator;
