#include "linked_list.h"

//===------------------------===//
// main()
//===------------------------===//


int main() {
  List<int> l;

  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  const List<int> l2 = l;

  List<int>::Iterator it1 = l.begin();
  List<int>::ConstIterator it2 = it1;
  ++it2;

  //*it = 10;

  l2.print();
}
