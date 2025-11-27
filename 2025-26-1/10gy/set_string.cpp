#include <iostream>
#include <set>

using set_iter = std::set<std::string>::iterator;

struct StringSizeLess {
  bool operator()(const std::string &lhs,
                  const std::string &rhs) const {
    return lhs.size() < rhs.size();
  }
};

int main() {
  std::set<std::string, StringSizeLess> s;
  s.insert("C++");
  s.insert("Java");
  s.insert("Haskell");
  s.insert("GOD");

  std::cout << s.size() << '\n';

  set_iter it = s.find("GOD");
  if (it == s.end())
    return -1;
  std::cout << "Found god: " << *it << '\n';
  //for (set_iter it = s.begin(); it != s.end(); ++it) {
  //  std::cout << *it << '\n';
  //}
}
