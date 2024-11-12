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

//===-------------------------===//
// List implementation
//===-------------------------===//

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
    this->push_back(ptr->data);
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
    this->push_back(ptr->data);
    ptr = ptr->next;
  }
  return *this;
}

void List::push_back(int data) {
  Node **ptr = &head;
  while (*ptr != nullptr)
    ptr = &(*ptr)->next;
  *ptr = new Node{data, nullptr};
}

void display(List &l) {
  for (ConstIterator it = l.begin(); it != l.end(); ++it) {
    std::cout << *it << '\n';
  }
}
