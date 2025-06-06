#include <iterator>
#include <vector>
#include "linked_list.h"

int main() {
  List<int> l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  l.push_back(4);
  std::vector<int> v = {1,2,3,4};

  auto lit = l.begin();
  auto vit = v.begin();

  std::advance(lit, 2);
  std::advance(vit, 2);
}
