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
    return lhs.x < rhs.x && lhs.y < rhs.y;
  }
};

int main() {
  std::set<Point, PointLess> sp;

  sp.insert(Point{0,1});
  sp.insert(Point{2,3});
  sp.insert(Point{0,8});

  for (Point p : sp) {
    std::cout << "(" << p.x << ", " << p.y << ")\n";
  }
}
