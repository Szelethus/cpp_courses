#include "linked_list.h"
#include <iostream>

//===--------------===//
// Iterator
//===--------------===//

Iterator Iterator::operator++() {
  ptr = ptr->next;
  return *this;
}

Iterator Iterator::operator++(int) {
  Iterator ret = *this;
  ++(*this);
  return ret;
}
int &Iterator::operator*() { return ptr->data; }

//===--------------===//
// ConstIterator
//===--------------===//

ConstIterator ConstIterator::operator++() {
  ptr = ptr->next;
  return *this;
}
int ConstIterator::operator*() { return ptr->data; }

//===--------------===//
// List
//===--------------===//

void List::free() {
  Node *ptr = head;
  while (ptr != nullptr) {
    Node *nextPtr = ptr->next;
    delete ptr;
    ptr = nextPtr;
  }
}

List::List(const List &other) {
  for (Node *ptr = other.head; ptr != nullptr; ptr = ptr->next) {
    push_back(ptr->data);
  }
}

List &List::operator=(const List &other) {
  if (this == &other)
    return *this;

  free();
  head = nullptr;

  for (Node *ptr = other.head; ptr != nullptr; ptr = ptr->next) {
    push_back(ptr->data);
  }
  return *this;
}

void List::push_back(int data) {
  Node **ptr = &head;
  while ((*ptr) != nullptr) {
    ptr = &(*ptr)->next;
  }
  *ptr = new Node{data, nullptr};
}

int List::length() const {
  int length = 0;
  for (Node *ptr = head; ptr != nullptr; ptr = ptr->next) {
    length++;
  }
  return length;
}

std::ostream &operator<<(std::ostream &out, const List &l) {
  for (ConstIterator it = l.begin(); it != l.end(); ++it) {
    out << *it << '\n';
  }
  return out;
}
