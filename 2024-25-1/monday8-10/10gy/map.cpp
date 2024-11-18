#include <iostream>
#include <map>

int main() {
  std::map<std::string, int> m;

  m["alma"] = 4;
  m["korte"] = 5;

  std::cout << "Value of \"alma\": " << m["alma"] << '\n';

  std::cout << "Value of \"edit\": " << m["edit"] << '\n';

  std::cout << "Size of map: " << m.size() << '\n';

  for (std::map<std::string, int>::iterator it = m.begin();
       it != m.end(); ++it) {
    std::cout << it->first << ' ' << it->second << '\n';
  }
}
