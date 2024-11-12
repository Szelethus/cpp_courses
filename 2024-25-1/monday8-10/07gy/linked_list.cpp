#include "linked_list.h"
#include <iostream>

//===-------------------------------------------------===//
// Iterator implementáció
//===-------------------------------------------------===//

namespace detail {
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
} // namespace detail

//===-------------------------------------------------===//
// ConstIterator implementáció
//===-------------------------------------------------===//

namespace detail {
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
} // namespace detail

//===-------------------------------------------------===//
// List implementáció
//===-------------------------------------------------===//

void List::free() {
  Node *ptr = head;
  while (ptr) {
    Node *nextPtr = ptr->next;
    delete ptr;
    ptr = nextPtr;
  }
}

// copy konstruktor (List l2 = l)
List::List(const List &other) {
  Node *ptr = other.head;
  while (ptr) {
    push_back(ptr->data);
    ptr = ptr->next;
  }
}

// értékadó operátor (l2 = l)
List &List::operator=(const List &other) {
  if (this == &other)
    return *this;

  free();
  head = nullptr;

  Node *ptr = other.head;
  while (ptr) {
    push_back(ptr->data);
    ptr = ptr->next;
  }
  return *this;
}

void List::push_back(int data) {
  Node **ptr = &head;
  while (*ptr)
    ptr = &(*ptr)->next;
  *ptr = new Node{data, nullptr};
}

void display(const List &l) {
  for (List::ConstIterator it = l.begin(); it != l.end(); ++it) {
    std::cout << *it << '\n';
  }
}
