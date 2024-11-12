#include <iostream>
#include <set>

int main() {
  std::set<int> s;

  for (int i = 10; i > 0; --i)
    s.insert(i);

  s.insert(8);
  s.insert(8);
  s.insert(8);

  std::set<int>::iterator begin = s.begin();
  //*begin = 30;

  for (std::set<int>::iterator it = s.begin(); it != s.end(); ++it) {
    std::cout << *it << '\n';
  }
}
