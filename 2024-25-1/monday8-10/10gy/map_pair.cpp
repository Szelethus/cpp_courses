#include <iostream>
#include <map>

int main() {
  std::map<std::string, int> m;

  std::pair<std::string, int> tmp{"alma", 4};

  m.insert(tmp);
  m.insert(std::pair<std::string, int>{"korte", 5});
  m.insert(std::make_pair("fa", 2));

  // using count + map[]
  if (m.count("alma") > 0)
    std::cout << "Value of \"alma\": " << m["alma"] << '\n';

  // using find
  std::map<std::string, int>::iterator it = m.find("alma");
  if (it != m.end())
    std::cout << "Value of \"alma\": " << it->second << '\n';

  it->second = 9999;

  std::cout << "Size of map: " << m.size() << '\n';

  for (std::map<std::string, int>::iterator it = m.begin();
       it != m.end(); ++it) {
    std::cout << it->first << ' ' << it->second << '\n';
  }
}
