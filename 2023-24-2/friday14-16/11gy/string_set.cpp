#include <iostream>
#include <algorithm>
#include <set>

struct StringSizeLess {
  bool operator()(std::string lhs, std::string rhs) const {
    return lhs.size() < rhs.size();
  }
};

int main() {
  std::set<std::string, StringSizeLess> s;
  s.insert("C++");
  s.insert("Haskell");
  s.insert("Java");
  s.insert("GOD");

  auto it = s.find("GOD");

  if (it == s.end()) {
    std::cout << "not found\n";
    return -1;
  }

  std::cout << *it << '\n';

  it = find(s.begin(), s.end(), "GOD");

  if (it == s.end()) {
    std::cout << "not found\n";
    return -1;
  }

  std::cout << *it << '\n';
}
