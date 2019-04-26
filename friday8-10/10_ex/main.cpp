#include "list.h"
#include <iostream>

int main() {
  List<int> l;
  List<std::string> l2;

  l.add(5);
  l.add(6);

  l2.add("Hello");
  l2.add("Bello");

  std::cout << l;

  for (List<int>::ConstIterator it = l.begin(); it != l.end(); ++it) {
    std::cout << *it << '\n';
  }

  for (List<std::string>::ConstIterator it = l2.begin(); it != l2.end(); ++it) {
    std::cout << *it << '\n';
  }

}
