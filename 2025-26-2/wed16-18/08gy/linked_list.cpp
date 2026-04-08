#include "linked_list.h"

//===-------------------------------------===//
// Iterator függvények
//===-------------------------------------===//
// ++it;
Iterator Iterator::operator++() {
  ptr = ptr->next;
  return *this;
}

// it++
Iterator Iterator::operator++(int) {
  Iterator pred = *this;
  ptr = ptr->next;
  return pred;
}

int &Iterator::operator*() { return ptr->data; }

//===-------------------------------------===//
// ConstIterator függvények
//===-------------------------------------===//
// ++it;
ConstIterator ConstIterator::operator++() {
  ptr = ptr->next;
  return *this;
}

// it++
ConstIterator ConstIterator::operator++(int) {
  ConstIterator pred = *this;
  ptr = ptr->next;
  return pred;
}

int ConstIterator::operator*() { return ptr->data; }

//===-------------------------------------===//
// List függvények
//===-------------------------------------===//

// másoló konstruktor
List::List(const List &other) {
  Node *ptr = other.head;
  while (ptr != nullptr) {
    push_back(ptr->data);
    ptr = ptr->next;
  }
}

// értékadó operátor
List &List::operator=(const List &other) {
  if (this == &other)
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

void List::push_back(int data) {
  Node **ptr = &head;

  while (*ptr != nullptr)
    ptr = &(*ptr)->next;

  *ptr = new Node{data, nullptr};
}

void List::print() const {
  Node *ptr = head;
  while (ptr != nullptr) {
    std::cout << ptr->data << '\n';
    ptr = ptr->next;
  }
}

void List::print2() {
  for (Iterator it = begin(); it != end(); ++it) {
    std::cout << *it << '\n';
  }
}

void List::free() {
  Node *ptr = head;
  while (ptr != nullptr) {
    Node *nextPtr = ptr->next;
    delete ptr;
    ptr = nextPtr;
  }
}
