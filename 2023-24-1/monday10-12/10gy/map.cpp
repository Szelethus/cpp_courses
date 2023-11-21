#include <iostream>
#include <map>

using map_iter = std::map<std::string, int>::iterator;

template <class T1, class T2>
struct pair {
  T1 first;
  T2 second;
};

void foo(const std::map<std::string, int> &m) {
  m["str"];
}

int main() {
  std::map<std::string, int> m;

  m.insert(std::make_pair("alma", 4));
  m.insert(std::make_pair("korte", 5));
  m.insert(std::make_pair("gizi", 4));

  if (m.count("")) {
    std::cout << "Emptry string in map\n";
  }

  map_iter it = m.find("alma");
  if (it == m.end())
    return -1;

  it->second = 5;

  for (map_iter it = m.begin(); it != m.end(); ++it) {
    std::pair<std::string, int> val = *it;
    std::cout << "(" << val.first << ", " << val.second << ")\n";
  }
}
