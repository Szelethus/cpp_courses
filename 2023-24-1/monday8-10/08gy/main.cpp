#include <iostream>
#include "linked_list.h"

void foo(List<int> &l1, List<int> &l2) {
  l1 = l2;
}

int main() {
  List<int> l{};
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  List l2(l);
  l2 = l;

  l = l;
  std::cout << l << '\n';

  List<int>::Iterator it = l.begin();
  // explicit ctor miatt nem lehet
  // it = nullptr;
  List<int>::ConstIterator cit = it;
  ++it;
  *it = 100;
  std::cout << *it << '\n';

}
