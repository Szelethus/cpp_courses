#include <iostream>
#include <set>

struct Point {
  int x;
  int y;
};

bool operator<(Point lhs, Point rhs) {
  return lhs.x < rhs.x && lhs.y < rhs.y;
}

struct PointLessByX {
  bool operator()(Point lhs, Point rhs) const {
    return lhs.x < rhs.x;
  }
};

int main() {
  std::set<Point, PointLessByX> sp;
  sp.insert(Point{0,1});
  sp.insert(Point{0,5});
  sp.insert(Point{2,2});
  sp.insert(Point{4,7});
  sp.insert(Point{3,9});

  for (std::set<Point, PointLessByX>::iterator it = sp.begin();
       it != sp.end(); ++it) {
    std::cout << it->x << ' ' << it->y << '\n';
  }
}
