#include <iostream>
#include <set>
#include <algorithm>

struct Point {
  int x, y;
};

bool operator==(Point lhs, Point rhs) {
  return lhs.x == rhs.x && rhs.y == lhs.y;
}

struct LessByX {
  bool operator()(Point a, Point b) const {
    return a.x < b.x;
  }
};

std::ostream &operator<<(std::ostream &out, Point p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

int main() {
  std::multiset<Point, LessByX> sp;

  sp.insert(Point{0,1});
  sp.insert(Point{0,2});

  auto it = sp.find(Point{0,2});
  std::cout << *it << '\n';

  it = std::find(sp.begin(), sp.end(), Point{0,2});
  std::cout << *it << '\n';
}
