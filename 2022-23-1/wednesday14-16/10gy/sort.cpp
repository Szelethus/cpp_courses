#include <iostream>
#include <vector>
#include <algorithm>

struct StringLength {
  bool operator()(const std::string &lhs, const std::string &rhs) const {
    return lhs.size() < rhs.size();
  }
};

int main() {
  std::vector<std::string> v;
  v.push_back("ADA");
  v.push_back("Java");
  v.push_back("1234567");
  v.push_back("Maci");
  v.push_back("C++");
  v.push_back("Haskell");
  sort(v.begin(), v.end(), StringLength());
  for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it)
    std::cout << *it << ' ';
}
