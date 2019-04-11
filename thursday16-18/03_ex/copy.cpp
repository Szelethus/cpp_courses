#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

struct Vec {
  int x, y;

  Vec() = default;
  Vec(int a, int b) : x(a), y(b) {}
  Vec(const Vec &other) {
    std::cout << "Copied!\n";
  }
  Vec& operator=(const Vec &other) {
    std::cout << "Assigned!\n";
    return *this;
  }
};


int main() {
  std::list<Vec> V;

  for (int i = 0; i < 10; ++i) {
    V.push_back(Vec(0, 1));
  }

  std::reverse(V.begin(), V.end());
}
