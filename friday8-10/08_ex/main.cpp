#include "list.h"
#include <iostream>
#include "header.h"

int main() {
  List l;

  l.add(5);
  l.add(6);

  std::cout << l;

}
