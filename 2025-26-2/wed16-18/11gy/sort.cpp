#include <iostream>
#include <vector>
#include <algorithm>

struct Descending {
  bool operator()(int lhs, int rhs) const {
    return lhs > rhs;
  }
};

int main() {
  std::vector<int> v = {4,2,3,5,1,6,7};

  std::sort(v.begin(), v.end(), Descending{});

  //std::set<int> s;

  //s.insert(v.begin(), v.end());
  //v.assign(s.begin(), s.end());

  for (int i : v)
    std::cout << i << '\n';

}
