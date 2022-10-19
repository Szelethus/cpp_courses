#include <iostream>
#include "linked_list.h"

int main() {
  List l;
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  Iterator it = l.begin();
  *it = 4;

  ConstIterator it2 = it;
  {
    const List l2 = l;
    l2.length();
  }

  List l2 = l;

  l = l2;

  std::cout << l << '\n';
}
