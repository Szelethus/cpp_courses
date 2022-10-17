#include <iostream>
#include "linked_list.h"

std::ostream &operator<<(std::ostream &out, const List &l) {
  for (ConstIterator it = l.begin(); it != l.end(); ++it) {
    out << *it << '\n';
  }
  return out;
}

Iterator Iterator::operator++() {
  ptr = ptr->next;
  return *this;
}
int &Iterator::operator*() { return ptr->data; }

ConstIterator ConstIterator::operator++() {
  ptr = ptr->next;
  return *this;
}
int ConstIterator::operator*() { return ptr->data; }
