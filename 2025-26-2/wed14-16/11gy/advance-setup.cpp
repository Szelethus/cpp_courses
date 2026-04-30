#include <iostream>
#include <vector>
#include <list>

int main() {
  std::vector<int> v = {1,2,3,4,5,6,7,8};

  std::vector<int>::iterator vecIt = v.begin();

  // hogyan léptetjük 3-mal előre?

  vecIt = vecIt + 3;

  std::list<int> l = {1,2,3,4,5,6,7,8};

  std::list<int>::iterator listIt = l.begin();

  // hogyan léptetjük 3-mal előre?

  ++listIt;
  ++listIt;
  ++listIt;
}
