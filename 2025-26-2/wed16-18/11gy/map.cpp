#include <iostream>
#include <map>

int main() {
  std::map<std::string, int> m;

  //m["alma"] = 4;
  //m["korte"] = 5;

  // operator[] mellékhatásos!!!
  //if (m["edit"])
  //  std::cout << m["edit"] << '\n';
  
  m.insert(std::pair<std::string, int>{"alma", 4});
  m.insert(std::make_pair("korte", 5));
  
  std::map<std::string, int>::iterator it = m.find("edit");
  if (it == m.end())
    std::cout << "edit not found\n";

  for (std::map<std::string, int>::iterator it = m.begin();
       it != m.end(); ++it) {
    std::pair<std::string, int> pair = *it;
    std::cout << pair.first << ", " << pair.second << '\n';
  }
}
