#include "linked_list.h"

//===----------------------------------------------------------===//
// Egyéb
//===----------------------------------------------------------===//

void foo(List<int> &l1, List<int> &l2) {
  l1 = l2;
}

int main() {
  List<int> l;
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  List<int>::Iterator it = l.begin();

  List<int>::ConstIterator cit = it;
}
