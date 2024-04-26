#include "linked_list.h"
#include "linked_list.h"
#include "linked_list.h"
#include <iostream>

int main() {
  List l;
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  ConstIterator it = l.begin();
  it = l.begin();

  const List l2 = l;

  std::cout << l2;
}
