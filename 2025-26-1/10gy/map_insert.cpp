#include <iostream>
#include <map>

int main() {
  std::map<std::string, int> m;

  m.insert(std::pair<std::string, int>("meggy", 10));
  m.insert(std::make_pair("alma", 5));
  m.insert({"korte", 10});

  std::map<std::string, int>::iterator f = m.find("paradicsom");
  if (f == m.end()) {
    std::cout << "not found!\n";
  }

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
