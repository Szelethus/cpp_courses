#include <iostream>
#include <set>

int main() {
  std::set<int> s;

  s.insert(2);
  s.insert(1);
  s.insert(1);
  s.insert(3);

  for (const int &i : s) {
    std::cout << i << '\n';
  }

  std::set<int>::iterator it = s.find(2);
  //auto it = s.find(2);

}
