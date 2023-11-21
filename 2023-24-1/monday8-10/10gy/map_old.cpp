#include <iostream>
#include <map>

template <class T1, class T2>
struct pair {
  T1 first;
  T2 second;
};

using map_iter = std::map<std::string, int>::iterator;

int main() {
  std::map<std::string, int> m;
  m["alma"] = 4;
  m["korte"] = 5;
  m["gizi"] = 4;

  //map_iter it = m.find("gizi");
  //if (it == m.end())
  //  return -1;

  //std::cout << it->second << '\n';
  
  if (m[""] == 0) {
    std::cout << "Empty string found in map\n";
  }

  for (std::pair<std::string, int> p : m) {
    std::cout << "(" << p.first << ", " << p.second << ")\n";
  }
}
