#include <iostream>
#include <set>

struct StringLength {
  bool operator()(const std::string &lhs,
                  const std::string &rhs) const {
    return lhs.size() <= rhs.size();
  }
};

using set_iter = std::set<std::string>::iterator;

int main() {
  std::set<std::string, StringLength> s;

  s.insert("Java");
  s.insert("Haskell");
  s.insert("C++");
  s.insert("GOD");

  set_iter it = s.find("GOD");

  if (it != s.end())
    std::cout << "Found GOD!: " << *it << "\n";

  //for (const std::string &str : s) {
  //  std::cout << str << '\n';
  //}
}
