#include "linked_list.h"

int main() {
  List l;
  
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  List::Iterator it = l.begin();
  List::ConstIterator cit = it;

  const List l2 = l;
  List::ConstIterator cit2 = l2.begin();
  ++cit2;
  //*it = 10;
  l2.display();

  List::Iterator it3 = List::Iterator{nullptr};
}
