#include <iostream>
#include <map>

template <class T1, class T2>
struct pair {
  T1 first;
  T2 second;
};

using map_iter = std::map<std::string, int>::iterator;

void foo(const std::map<std::string, int> &m) {
  m["str"]; // operator[] nem konstans
}

int main() {
  std::map<std::string, int> m;
  m.insert(std::make_pair("alma", 4));
  m.insert(std::make_pair("korte", 5));
  m.insert(std::make_pair("gizi", 4));

  if (m.count("")) {
    std::cout << "Empty string found in map\n";
  }

  for (std::pair<std::string, int> p : m) {
    std::cout << "(" << p.first << ", " << p.second << ")\n";
  }
}
