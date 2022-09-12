#include <iostream>
#include "list.h"

int main() {
  List l{};

  l.add(5);
  l.add(6);
  l.add(7);
  l.print();

  for (List::Iterator it = l.begin(); it != l.end(); ++it) {
    *it += 1;
  }

  for (List::Iterator it = l.begin(); it != l.end(); ++it) {
    std::cout << *it << '\n';
  }
}
