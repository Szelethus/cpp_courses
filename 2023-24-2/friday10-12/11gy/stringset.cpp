#include <iostream>
#include <set>

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

  std::cout << s.size() << "\n";
  std::cout << s.count("GOD") << "\n";
  std::set<std::string, strless>::iterator it = s.find("GOD");
  
  if (it == s.end()) {
    std::cout << "GOD not in s\n";
    return -1;
  }

  std::cout << *it << '\n';
}
