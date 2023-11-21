#include <iostream>
#include <map>

using map_iter = std::map<std::string, int>::iterator;

template <class T1, class T2>
struct pair {
  T1 first;
  T2 second;
};

int main() {
  std::map<std::string, int> m;

  m["alma"] = 4;
  m["korte"] = 5;
  m["gizi"] = 4;

  if (m[""] == 5) {
    std::cout << "Emptry string in map\n";
  }

  for (map_iter it = m.begin(); it != m.end(); ++it) {
    std::pair<std::string, int> val = *it;
    std::cout << "(" << val.first << ", " << val.second << ")\n";
  }
}
