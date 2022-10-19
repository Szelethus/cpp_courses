#include <iostream>
#include "linked_list.h"

std::ostream &operator<<(std::ostream &out, const List &l) {
  for (ConstIterator it = l.begin(); it != l.end(); ++it) {
    out << *it << '\n';
  }
  return out;
}

//===---------------------------===//
// Iterator
//===---------------------------===//

// Iterator and ConstIterator method definitions.
Iterator Iterator::operator++() {
  ptr = ptr->next;
  return *this;
}

Iterator Iterator::operator++(int) {
  Iterator ret = *this;
  ptr = ptr->next;
  return ret;
}
int &Iterator::operator*() { return ptr->data; }

//===---------------------------===//
// ConstIterator
//===---------------------------===//

ConstIterator ConstIterator::operator++() {
  ptr = ptr->next;
  return *this;
}
int ConstIterator::operator*() { return ptr->data; }
