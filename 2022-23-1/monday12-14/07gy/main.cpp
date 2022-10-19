#include "linked_list.h"
#include <iostream>

int main() {
  List<int> l;
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);
  List<int>::Iterator it = l.begin();
}
