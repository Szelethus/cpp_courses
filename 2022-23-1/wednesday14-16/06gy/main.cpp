#include <iostream>
#include "linked_list.h"

int main() {
  List l{};
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  Iterator it = l.begin();
  *it = 4;
  std::cout << l << '\n';

  const List l2(l);

  ConstIterator it2 = l.begin();

  std::cout << '\n';
  std::cout << l2 << '\n';
}
