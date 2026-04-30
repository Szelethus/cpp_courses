#include <iostream>
#include <vector>
#include <algorithm>
//#include <set>

struct Descending {
  bool operator()(int lhs, int rhs) const {
    return lhs > rhs;
  }
};

int main() {
  std::vector<int> v = {1,4,2,5,3,7,6};

  //std::set<int> s;
  //s.insert(v.begin(), v.end());
  //v.assign(s.begin(), s.end());

  std::sort(v.begin(), v.end(), Descending{});

  for (int i : v) {
    std::cout << i << '\n';
  }
}
