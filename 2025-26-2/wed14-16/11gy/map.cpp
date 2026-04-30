#include <iostream>
#include <map>

int main() {
  std::map<std::string, int> m;

  m["alma"] = 4;
  m["korte"] = 5;

  // [] operátor mellékhatásos!!! nem így kérdezzük le a tartalmazást
  //if (m["edit"])
  //  std::cout << m["edit"] << '\n';

  m.insert(std::pair<std::string, int>{"kocsi", 5});
  m.insert(std::make_pair("hajo", 4));

  std::map<std::string, int>::iterator editIt = m.find("edit");
  if (editIt == m.end())
    std::cout << "'edit' not in map\n";

  for (std::map<std::string, int>::iterator it = m.begin();
       it != m.end(); ++it) {
    std::pair<std::string, int> value = *it;
    std::cout << value.first << ", " << value.second << '\n';
  }
}
