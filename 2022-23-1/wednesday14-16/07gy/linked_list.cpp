#include "linked_list.h"
#include <iostream>

std::ostream &operator<<(std::ostream &out, const List &l) {
  for (List::ConstIterator it = l.begin(); it != l.end(); ++it) {
    out << *it << '\n';
  }
  return out;
}

namespace list_detail {
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
} // end of namespace list_detail

int List::counter = 0;

void List::free() {
  Node *ptr = head;
  while (ptr != nullptr) {
    Node *nextPtr = ptr->next;
    delete ptr;
    ptr = nextPtr;
  }
}

List::List(const List &other) {
  ++counter;
  for (ConstIterator it = other.begin(); it != other.end(); ++it) {
    push_back(*it);
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
