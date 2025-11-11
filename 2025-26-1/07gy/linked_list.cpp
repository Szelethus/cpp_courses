#include "linked_list.h"

//===----------------------------------------------------------===//
// Iterator implementáció
//===----------------------------------------------------------===//

namespace detail {

// tagfüggvény definicio
int &Iterator::operator*() { return ptr->data; }

Iterator Iterator::operator++() {
  ptr = ptr->next;
  return *this;
}

Iterator Iterator::operator++(int) {
  Iterator prev = *this;
  ptr = ptr->next;
  return prev;
}

} // end of namespace detail

//===----------------------------------------------------------===//
// ConstIterator implementáció
//===----------------------------------------------------------===//

namespace detail {
// tagfüggvény definicio
const int &ConstIterator::operator*() { return ptr->data; }

ConstIterator ConstIterator::operator++() {
  ptr = ptr->next;
  return *this;
}

ConstIterator ConstIterator::operator++(int) {
  ConstIterator prev = *this;
  ptr = ptr->next;
  return prev;
}
} // end of namespace detail

//===----------------------------------------------------------===//
// List implementáció
//===----------------------------------------------------------===//

void List::free() {
  Node *ptr = head;
  while (ptr != nullptr) {
    Node *nextPtr = ptr->next;
    delete ptr;
    ptr = nextPtr;
  }
}

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

void List::display() const {
  Node *ptr = head;
  while (ptr != nullptr) {
    std::cout << ptr->data << '\n';
    ptr = ptr->next;
  }
}

void List::display2() const {
  for (ConstIterator it = begin(); it != end(); ++it) {
    std::cout << *it << '\n';
  }
}

std::ostream &operator<<(std::ostream &out, const List &l) {
  for (List::ConstIterator it = l.begin(); it != l.end(); ++it)
    out << *it << '\n';
  return out;
}
