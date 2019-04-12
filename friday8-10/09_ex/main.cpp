#include "list.h"
#include <iostream>

int main() {
  List<int> l;

  l.add(5);
  l.add(6);

  std::cout << l;

  for (ConstIterator<int> it = l.begin(); it != l.end(); ++it) {
    std::cout << *it << '\n';
  }

}
