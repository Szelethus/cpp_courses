#include <iostream>
#include <vector>
#include <algorithm>
#include "linked_list.h"

using vec_iter = std::vector<int>::iterator;

struct IsEven {
  bool operator()(int i) {
    return i % 2 == 0;
  }
};

int main() {
  std::vector<int> vec = {5, 2, 8, 6, 1};
  vec_iter vit = find_if(vec.begin(), vec.end(), IsEven{});

  if (vit != vec.end()) {
    std::cout << *vit << '\n';
  }

  List<int> l;
  l.push_back(5);
  l.push_back(2);
  l.push_back(8);
  l.push_back(6);
  l.push_back(1);

  List<int>::iterator lit = std::find(l.begin(), l.end(), 6);
}
