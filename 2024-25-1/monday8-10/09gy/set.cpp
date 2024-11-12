#include <iostream>
#include <set>

struct Point {
  int x;
  int y;
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
  std::set<int> s;
  for (int i = 10; i > 0; --i) {
    s.insert(i);
  }

  //for (std::set<int>::iterator it = s.begin(); it != s.end(); ++it)
  //  std::cout << *it << '\n';

  std::set<Point, PointLess> sp;

  sp.insert(Point{0, 1});
  sp.insert(Point{3, 1});
  sp.insert(Point{0, 5});

  for (std::set<Point, PointLess>::iterator it = sp.begin();
       it != sp.end(); ++it) {
    std::cout << it->x << ' ' << it->y << '\n';
  }
}
