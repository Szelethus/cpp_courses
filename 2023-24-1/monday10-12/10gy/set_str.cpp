#include <iostream>
#include <set>

struct strlen {
  bool operator()(std::string left, std::string right) const {
    return left.size() <= right.size();
  }
};

using set_iter = std::set<std::string, strlen>::iterator;

int main() {
  std::set<std::string, strlen> s;
  s.insert("C++");
  s.insert("Java");
  s.insert("Haskell");
  s.insert("GOD");

  set_iter it = s.find("GOD");

  if (it == s.end())
    std::cout << "GOD is not in s\n";

  //std::cout << *it << '\n';

  for (std::string str : s)
    std::cout << str << '\n';

  std::cout << s.size() << '\n';
}
