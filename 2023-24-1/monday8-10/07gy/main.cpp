#include <iostream>
#include "linked_list.h"

void foo(List &l1, List &l2) {
  l1 = l2;
}

int main() {
  List l{};
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  List l2(l);
  l2 = l;

  l = l;
  display(l);

  Iterator it = l.begin();
  // explicit ctor miatt nem lehet
  // it = nullptr;
  ConstIterator cit = it;
  ++it;
  *it = 100;
  std::cout << *it << '\n';

}
