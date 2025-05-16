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

  s.erase(3);

  std::set<int>::iterator it = s.find(0);
  // If the element is not found in the set
  if (it == s.end())
    return -1;

  for (std::set<int>::iterator it = s.begin(); it != s.end(); ++it)
    std::cout << *it << '\n';
}
