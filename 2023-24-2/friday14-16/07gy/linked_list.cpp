#include "linked_list.h"

ConstIterator::ConstIterator(Iterator it) : ptr(it.ptr) {}

// prefix++
ConstIterator ConstIterator::operator++() {
  ptr = ptr->next;
  return *this;
}

// postfix++
ConstIterator ConstIterator::operator++(int) {
  ConstIterator ret = *this;
  ptr = ptr->next;
  return *this;
}

// prefix++
Iterator Iterator::operator++() {
  ptr = ptr->next;
  return *this;
}

// postfix++
Iterator Iterator::operator++(int) {
  Iterator ret = *this;
  ptr = ptr->next;
  return *this;
}

std::ostream &operator<<(std::ostream &out, const List &l) {
  for (ConstIterator it = l.begin(); it != l.end(); ++it) {
    out << *it << '\n';
  }
  return out;
}

void List::push_back(int data) {
  Node **ptr = &head;

  while (*ptr)
    ptr = &(*ptr)->next;

  *ptr = new Node{data, nullptr};
}

List::List(const List &other) {
  Node *ptr = other.head;
  while (ptr) {
    push_back(ptr->data);
    ptr = ptr->next;
  }
}

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

void List::free() {
  Node *ptr = head;
  while (ptr) {
    Node *nextPtr = ptr->next;
    delete ptr;
    ptr = nextPtr;
  }
}
