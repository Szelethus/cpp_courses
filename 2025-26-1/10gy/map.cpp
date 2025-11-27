#include <iostream>
#include <map>

int main() {
  std::map<std::string, int> m;
  m["alma"] = 4;

  if (m["korte"] == 0) {
    ;
  }

  m["alma"] = 8;

  for (std::map<std::string, int>::iterator it = m.begin();
       it != m.end(); ++it) {
    std::cout << it->first << ' ' << it->second << '\n';
  }
  //for (std::map<std::string, int>::iterator it = m.begin();
  //     it != m.end(); ++it) {
  //  std::pair<std::string, int> pair  = *it;
  //  std::cout << pair.first << ' ' << pair.second << '\n';
  //}
}
