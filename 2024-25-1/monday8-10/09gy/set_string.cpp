#include <iostream>
#include <set>

struct StringSizeLess {
  bool operator()(const std::string &lhs,
                  const std::string &rhs) const{
    return lhs.size() <= rhs.size();
  }
};

int main() {
  std::set<std::string, StringSizeLess> s;

  s.insert("C++");
  s.insert("Haskell");
  s.insert("Java");
  s.insert("GOD");

  if (s.count("GOD") > 0)
    std::cout << "Found God\n";
  std::cout << s.size() << '\n';

  std::set<std::string, StringSizeLess>::iterator it = s.find("GOD");

  if (it == s.end())
    return -1;

  std::cout << *it << '\n';

}
