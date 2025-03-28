#include "linked_list.h"
#include <iostream>

// ++prefix
Iterator &Iterator::operator++() {
  ptr = ptr->next;
  return *this;
}

// postfix++
Iterator Iterator::operator++(int) {
  Iterator ret = *this;
  ptr = ptr->next;
  return ret;
}

int &Iterator::operator*() { return ptr->data; }

// ++prefix
ConstIterator &ConstIterator::operator++() {
  ptr = ptr->next;
  return *this;
}

// postfix++
ConstIterator ConstIterator::operator++(int) {
  ConstIterator ret = *this;
  ptr = ptr->next;
  return ret;
}

int ConstIterator::operator*() { return ptr->data; }

void display(const List &l) {
  for (ConstIterator it = l.begin();
       it != l.end(); ++it) {
    std::cout << *it << '\n';
  }
}
