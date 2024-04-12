#include "linked_list.h"


// Prefix++
Iterator Iterator::operator++() {
  ptr = ptr->next;
  return *this;
}
// Postfix++
Iterator Iterator::operator++(int) {
  Iterator ret = *this;
  ptr = ptr->next;
  return ret;
}

// Prefix++
ConstIterator ConstIterator::operator++() {
  ptr = ptr->next;
  return *this;
}
// Postfix++
ConstIterator ConstIterator::operator++(int) {
  ConstIterator ret = *this;
  ptr = ptr->next;
  return ret;
}

std::ostream &operator<<(std::ostream &out, const List &l) {
  for (ConstIterator it = l.begin(); it != l.end(); ++it) {
    out << *it << '\n';
  }
  return out;
}

void List::free() {
  Node *ptr = head;
  while (ptr) {
    Node *nextPtr = ptr->next;
    delete ptr;
    ptr = nextPtr;
  }
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

void List::push_back(int data) {
  Node **ptr = &head;
  while (*ptr)
    ptr = &(*ptr)->next;
  *ptr = new Node{data, nullptr};
}
