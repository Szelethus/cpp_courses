#include <iostream>
#include <vector>
#include <list>

int main() {
  std::vector<int> v = {1,2,3,4,5,6,7};
  std::vector<int>::iterator it = v.begin();

  // hogyan tudok ezen 3-at léptetni?
  
  it = it + 3;

  std::list<int> l = {1,2,3,4,5,6,7};
  std::list<int>::iterator listIt = l.begin();

  // hogyan tudok ezen 3-at léptetni?
  
  ++listIt;
  ++listIt;
  ++listIt;
}
