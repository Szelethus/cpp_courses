#include "linked_list.h"

void foo(List &l1, List &l2) {
  l1 = l2;
}

int main() {
  List l;
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  const List l2{l};

  ConstIterator it = l2.begin();

  it++;

  l2.display();

}
