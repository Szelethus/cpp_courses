#include <iostream>
#include "linked_list.h"

int main() {
  List<int> l{};
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  List<int>::iterator it = l.begin();
  *it = 4;
  std::cout << l << '\n';

  const List<int> l2(l);

  List<int>::Constiterator it2 = l.begin();

  std::cout << '\n';
  std::cout << l2 << '\n';
}
