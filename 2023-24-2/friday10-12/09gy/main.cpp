#include "linked_list.h"

int main() {
  List<int> l;
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  List<int>::Iterator it = l.begin();
  List<int>::ConstIterator cit = it;

  const List l2 = l;

  std::cout << l2 << '\n';
}
