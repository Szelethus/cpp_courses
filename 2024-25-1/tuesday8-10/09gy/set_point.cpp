#include <iostream>
#include <set>

struct Point {
  int x, y;
};

bool operator<(Point lhs, Point rhs) {
  return lhs.x < rhs.x;
}

struct PointLess {
  bool operator()(Point lhs, Point rhs) const {
    return lhs.x < rhs.x;
  }
};

int main() {
  std::set<Point, PointLess> s;
  s.insert(Point{0,1});
  s.insert(Point{3,2});
  s.insert(Point{0,3});

  for (std::set<Point, PointLess>::iterator it = s.begin();
       it != s.end(); ++it) {
    std::cout << it->x << ' ' << it->y << '\n';
  }
}
