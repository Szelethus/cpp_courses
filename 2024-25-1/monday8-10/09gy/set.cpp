#include <iostream>
#include <set>

struct StringLengthLess {
  bool operator()(const std::string &lhs, const std::string &rhs) const {
    return lhs.size() < rhs.size();
  }
};

int main() {
  std::set<std::string, StringLengthLess> s;
  s.insert("C++");
  s.insert("Java");
  s.insert("Haskell");
  s.insert("GOD");

  auto it = s.find("GOD");

  if (it == s.end())
    return -1;

  std::cout << *it << '\n';
}
