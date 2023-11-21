#include <iostream>
#include <set>

struct Point {
  int x, y;
};

std::ostream &operator<<(std::ostream &out, Point p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

struct LessByX {
  bool operator()(Point left, Point right) const {
    return left.x < right.x;
  }
};

using set_iter = std::set<Point>::iterator;

int main() {
  std::set<Point, LessByX> s;
  s.insert(Point{0,1});
  s.insert(Point{0,2});

  for (set_iter it = s.begin(); it != s.end(); ++it) {
    Point p = *it;
    std::cout << p << '\n';
  }
}
