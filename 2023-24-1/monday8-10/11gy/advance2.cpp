#include <iostream>
#include <algorithm>
#include <iterator>
#include "linked_list.h"

int main() {
  List<int> l;
  l.push_back(4);
  l.push_back(4);
  l.push_back(4);
  l.push_back(4);

  auto it = l.begin();
  std::advance(it, 2);
}

