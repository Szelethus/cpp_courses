#include <iostream>
#include "list.h"

int main() {
  List l{};
  l.add(5);
  l.add(7);
  l.add(8);
  l.add(9);

  for (Iterator it = l.begin(); it != l.end(); ++it) {
    *it = 5;
    std::cout << *it << '\n';
  }

}
