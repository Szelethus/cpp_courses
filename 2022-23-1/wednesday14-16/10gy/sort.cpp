#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

struct StringLength {
  bool operator()(const std::string &lhs, const std::string &rhs) const {
    return lhs.size() < rhs.size();
  }
};

struct Mod3 {
  bool operator()(int a, int b) {
    return a % 3 < b % 3;
  }
};

int main() {
  std::vector<int> vec{3, 2, 4, 1, 5, 7, 6};
  std::stable_sort(vec.begin(), vec.end(), Mod3{});
  //std::set<int> s{vec.begin(), vec.end()};
  //vec.assign(s.begin(), s.end());
  for (int i : vec) {
    std::cout << i << '\n';
  }

}
