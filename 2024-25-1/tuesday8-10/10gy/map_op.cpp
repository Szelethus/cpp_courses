#include <iostream>
#include <map>

int main() {
  std::map<std::string, int> m;

  std::pair<std::string, int> tmp{"alma", 4};
  m.insert(tmp);
  m.insert(std::pair<std::string, int>{"korte", 5});
  m.insert(std::make_pair("edit", 0));

  // using map[]
  if (m.count("panda") > 0)
    std::cout << "Value of panda: " << m["panda"] << '\n';

  // using map::find
  std::map<std::string, int>::iterator it = m.find("edit");
  if (it != m.end()) {
    std::cout << "Value of edit: " << it->second << '\n';

    it->second = 9999;
  }

  std::cout << "Size: " << m.size() << '\n';

  for (std::map<std::string, int>::iterator it = m.begin();
       it != m.end(); ++it) {
    std::cout << it->first << ' ' << it->second << '\n';
  }
}
