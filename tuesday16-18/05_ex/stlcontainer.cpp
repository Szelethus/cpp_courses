#include <iostream>
#include <set>

struct StringSizeLess {
  bool operator()(const std::string &lhs, const std::string &rhs) {
    return lhs.size() < rhs.size();
  }
};

int main() {
  std::set<std::string, StringSizeLess> s = {"god", "c++", "hello", "sajtocska"};

  for (auto it = s.begin(); it != s.end(); ++it) {
    std::cout << *it << '\n';
  }


}
