#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "linked_list.h"

int main() {
  std::vector<int> v = {1,2,3,4};

  std::vector<int>::iterator it = v.begin();
  std::advance(it, 2);

  List<int> l;
  l.push_back(4);
  l.push_back(4);
  l.push_back(4);
  l.push_back(4);

  List<int>::Iterator it2 = l.begin();
  std::advance(it2, 2);
}
