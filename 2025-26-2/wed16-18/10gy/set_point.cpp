#include <iostream>
#include <set>

struct Point {
  int x, y;
};

bool operator<(Point lhs, Point rhs) {
  return lhs.x < rhs.x;
}

struct PointLessByX {
  bool operator()(Point lhs, Point rhs) const {
    return lhs.x < rhs.x;
  }
};

using set_iter = std::set<Point>::iterator;

int main() {
  std::set<Point, PointLessByX> s;

  s.insert(Point{2,3});
  s.insert(Point{-6,9});
  s.insert(Point{2,6});

  for (set_iter it = s.begin(); it != s.end(); ++it) {
    std::cout << "(" << it->x << ", " << it->y << ")\n";
  }
}
