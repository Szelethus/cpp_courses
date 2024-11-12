#include "linked_list.h"

int main() {
  List l;
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  const List l2 = l;

  List::Iterator it = l.begin();

  List::ConstIterator cit = it;

}
