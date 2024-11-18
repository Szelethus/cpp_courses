#include <iostream>
#include <algorithm>
#include <vector>

struct StringLengthLess {
  bool operator()(const std::string &lhs,
                  const std::string &rhs) const {
    return lhs.size() < rhs.size();
  }
};

int main() {
  std::vector<std::string> v{"h", "io", "abc", "a", "k", "aa"};

  std::stable_sort(v.begin(), v.end(), StringLengthLess{});

  for (int i = 0; i < v.size(); ++i) {
    std::cout << v[i] << '\n';
  }
}
