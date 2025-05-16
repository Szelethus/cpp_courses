#include "linked_list.h"

int main() {
  List l;

  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  List::Iterator it = l.begin();
  List::ConstIterator cit = it;

  List::Iterator nit = List::Iterator{nullptr};

  const List l3 = l;

  //ConstIterator it = l3.begin();
  //++it;

  ////*it = 5;

  //l3.display();
}
