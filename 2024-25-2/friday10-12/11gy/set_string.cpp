#include <iostream>
#include <set>

struct StringLength {
  bool operator()(const std::string &lhs,
                  const std::string &rhs) const {
    return lhs.size() <= rhs.size();
  }
};

int main() {
  std::set<std::string, StringLength> lang;  

  lang.insert("C++");
  lang.insert("Java");
  lang.insert("Haskell");
  lang.insert("GOD");

  std::cout << lang.size() << '\n';

  if (lang.count("GOD") == 1)
    std::cout << "GOD found!\n";

  auto it = lang.find("GOD");
  if (it == lang.end())
    return -1;

  std::cout << "GOD is: " << *it << '\n';
}
