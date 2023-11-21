#include <iostream>
#include <set>

struct Point {
  int x, y;
};

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
  std::set<Point, LessByX> sp;

  sp.insert(Point{0,1});
  sp.insert(Point{0,2});

  for (const Point &i : sp) {
    std::cout << i << '\n';
  }
}
