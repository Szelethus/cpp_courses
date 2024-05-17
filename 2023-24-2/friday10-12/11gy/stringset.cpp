#include <iostream>
#include <set>
#include <algorithm>

struct strless {
  bool operator()(std::string a, std::string b) const {
    return a.size() < b.size();
  }
};

int main() {
  std::set<std::string, strless> s;
  s.insert("C++");
  s.insert("Java");
  s.insert("Haskell");
  s.insert("GOD");

  std::cout << s.size() << '\n';

  auto it = s.find("GOD");

  if (it == s.end()) {
    std::cout << "not found with set::find\n";
    return -1;
  }

  std::cout << *it << '\n';

  it = std::find(s.begin(), s.end(), "GOD");

  if (it == s.end()) {
    std::cout << "not found with set::find\n";
    return -1;
  }
}
