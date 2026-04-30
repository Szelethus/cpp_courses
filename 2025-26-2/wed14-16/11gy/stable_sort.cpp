#include <iostream>
#include <vector>
#include <algorithm>
//#include <set>

struct StrLength {
  bool operator()(std::string lhs, std::string rhs) const {
    return lhs.size() < rhs.size();
  }
};

int main() {
  std::vector<std::string> v = {"alma", "edit", "korte", "kocsi",
                                "almafa", "matek", "analizis"};

  //std::set<int> s;
  //s.insert(v.begin(), v.end());
  //v.assign(s.begin(), s.end());

  std::stable_sort(v.begin(), v.end(), StrLength{});

  for (std::string i : v) {
    std::cout << i << '\n';
  }
}
