#include <iostream>
#include <set>

struct Point {
  int x, y;
};

int main() {
  std::set<int> s = {1, 3, 4, 2, 6, 5};
  std::set<Point> sp;

  sp.insert(Point{0,1});

  s.insert(0);
  s.insert(0);

  for (int i : s) {
    std::cout << i << '\n';
  }
}
