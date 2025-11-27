#include <iostream>
#include <set>

struct Point {
  int x, y;
};

bool operator<(Point lhs, Point rhs) {
  return lhs.x < rhs.x;
}

// funktor
struct PointCompare {
  bool operator()(Point lhs, Point rhs) const {
    if (lhs.x < rhs.x)
      return false;
    if (lhs.y < rhs.y)
      return false;
    return true;
  }
};

using set_iter = std::set<Point>::iterator;

int main() {
  std::set<Point> s;

  s.insert(Point{1,3});
  s.insert(Point{2,5});
  s.insert(Point{2,7});

  for (set_iter it = s.begin(); it != s.end(); ++it) {
    std::cout << "(" << it->x << ", " << it->y << ")\n";
  }

  set_iter it = s.find(Point{1,8});
  if (it != s.end())
    std::cout << "found\n";
}
