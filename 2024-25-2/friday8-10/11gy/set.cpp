#include <iostream>
#include <set>

int main() { 
  std::set<int> s;

  s.insert(1);
  s.insert(0);
  s.insert(0);
  s.insert(4);
  s.insert(3);
  s.insert(2);

  for (std::set<int>::iterator it = s.begin(); it != s.end(); ++it)
    std::cout << *it << '\n';
}
