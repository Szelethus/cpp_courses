#include "linked_list.h"
#include <iostream>
#include <vector>

List getList() {
  List l;
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);
  return l;
}

std::vector<int> getVector() {
  return {5, 6, 7};
}

int main() {
  int sum = 0;

  std::cout << sum << '\n';
}
