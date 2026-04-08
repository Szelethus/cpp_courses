#include "linked_list.h"

//===-------------------------------------===//
// main()
//===-------------------------------------===//

int main() {
  List l;

  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  const List l2 = l;

  Iterator it1 = l.begin();
  ConstIterator it2 = it1;
  ++it2;
  //*it = 10;

  l2.print();
}
