#include <iostream>
#include <set>

struct StringLength {
  bool operator()(const std::string &lhs,
                  const std::string &rhs) const {
    return lhs.size() <= rhs.size();
  }
};

int main() {
  std::set<std::string, StringLength> s;

  s.insert("C++");
  s.insert("Java");
  s.insert("Haskell");
  s.insert("GOD");

  if (s.count("GOD"))
    std::cout << "Found GOD\n";

  std::cout << s.size() << '\n';

  std::set<std::string, StringLength>::iterator it = s.find("GOD");
  if (it == s.end())
    return -1;

  std::cout << *it << '\n';
}
