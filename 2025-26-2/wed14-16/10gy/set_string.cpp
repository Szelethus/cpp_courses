#include <iostream>
#include <set>

using set_iter = std::set<std::string>::iterator;

struct StringLength {
  bool operator()(const std::string &lhs,
                  const std::string &rhs) const {
    return lhs.size() <= rhs.size();
  }
};

int main() {
  std::set<std::string, StringLength> s;

  s.insert("Java");
  s.insert("Haskell");
  s.insert("C++");
  s.insert("GOD");

  set_iter it = s.find("GOD");
  if (it != s.end()) {
    std::cout << "Found GOD!\n";
    std::cout << *it << '\n';
  }

  //for (set_iter it = s.begin(); it != s.end(); ++it) {
  //  std::cout << *it << '\n';
  //}
}
