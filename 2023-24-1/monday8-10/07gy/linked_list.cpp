#include "linked_list.h"
#include <iostream>

// ---------------------------------------------------
Iterator Iterator::operator++() {
  ptr = ptr->next;
  return *this;
}

Iterator Iterator::operator++(int) {
  Iterator prev = *this;
  ptr = ptr->next;
  return prev;
}

Iterator::operator ConstIterator() { return ConstIterator(ptr); }

// ---------------------------------------------------
ConstIterator ConstIterator::operator++() {
  ptr = ptr->next;
  return *this;
}

// postfix opearátor
ConstIterator ConstIterator::operator++(int) {
  ConstIterator prev = *this;
  ptr = ptr->next;
  return prev;
}

// ---------------------------------------------------
List::List(const List &other) : head(nullptr) {
  Node *ptr = other.head;
  while (ptr != nullptr) {
    push_back(ptr->data);
    ptr = ptr->next;
  }
}

List &List::operator=(const List &other) {
  if (&other == this)
    return *this;
  free();
  head = nullptr;
  Node *ptr = other.head;
  while (ptr != nullptr) {
    push_back(ptr->data);
    ptr = ptr->next;
  }
  return *this;
}

void List::free() {
  Node *ptr = head;
  while (ptr != nullptr) {
    Node *nextPtr = ptr->next;
    delete ptr;
    ptr = nextPtr;
  }
}

void List::push_back(int data) {
  Node **ptr = &head;
  while (*ptr != nullptr) {
    ptr = &(*ptr)->next;
  }
  *ptr = new Node{data, nullptr};
}

std::ostream &operator<<(std::ostream &out, const List &l) {
  for (ConstIterator it = l.begin(); it != l.end(); ++it) {
    out << *it << '\n';
  }
  return out;
}
