#include <functional>
#include <iostream>
#include <algorithm>

struct Greater {
  bool operator()(int lhs, int rhs) const { 
    return lhs > rhs;
  }
};

struct Modulo3 {
  bool operator()(int lhs, int rhs) const {
    return (lhs % 3) < (rhs % 3);
  }
};

int main() {
  std::vector<int> v{0,1,4,3,7,5,6,2};

  std::stable_sort(v.begin(), v.end(), Modulo3{});

  for (int i = 0; i < v.size(); ++i)
    std::cout << v[i] << '\n';
}
