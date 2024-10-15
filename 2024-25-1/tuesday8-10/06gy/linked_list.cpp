#include "linked_list.h"


//===-------------------------===//
// Iterator implementation
//===-------------------------===//
Iterator &Iterator::operator++() {
  ptr = ptr->next;
  return *this;
}
Iterator Iterator::operator++(int) {
  Iterator curr = *this;
  ptr = ptr->next;
  return curr;
}

int &Iterator::operator*() { return ptr->data; }

//===-------------------------===//
// ConstIterator implementation
//===-------------------------===//
ConstIterator &ConstIterator::operator++() {
  ptr = ptr->next;
  return *this;
}
ConstIterator ConstIterator::operator++(int) {
  ConstIterator curr = *this;
  ptr = ptr->next;
  return curr;
}

int ConstIterator::operator*() { return ptr->data; }

void List::display() const {
  for (ConstIterator it = begin(); it != end(); ++it) {
    std::cout << *it << '\n';
  }
}
