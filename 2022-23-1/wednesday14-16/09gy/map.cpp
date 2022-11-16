#include <iostream>
#include <map>

using map_iter = std::map<int, std::string>::iterator;
using map_const_iter = std::map<int, std::string>::const_iterator;

void printMap(const std::map<int, std::string> &map) {
  for (map_const_iter it = map.begin(); it != map.end(); ++it) {
    std::cout << "(" << it->first << ", " << it->second << ")" << '\n';
  }
}

int main() {
  std::map<int, std::string, std::less<int>> map;

  map[4] = "Dénes";
  map[4] = "Dani";

  if (map[0] == "C++") {
    std::cout << "Contained!\n";
  }

  const std::map<int, std::string> m2 = map;

  // Insert
  std::pair<int, std::string> elem(1, "Andris");
  map.insert(elem);

  map.insert(std::pair<int, std::string>(2, "Béla"));

  map.insert(std::make_pair(3, "Cecília"));

  printMap(map);
}
