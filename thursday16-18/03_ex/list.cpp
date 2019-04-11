#include <iostream>
#include "list.h"

void List::free() {
  Node *current = head;

  while (current != nullptr) {
    Node *tmp = current->next;
    delete current;
    current = tmp;
  }
}

void List::copyElementsFromList(const List &other) {
  for (Node *ptr = other.head; ptr != nullptr; ptr = ptr->next) {
    add(ptr->data);
  }
}

void List::add(int data_) {
  if (head == nullptr) {
    head = new Node(data_);
    return;
  }

  Node *ptr = head;

  while (ptr->next != nullptr) {
    ptr = ptr->next;
  }

  ptr->next = new Node(data_);
}

List::List(int size) : head(nullptr) {
  for (int i = 0; i < size; ++i) {
    add(0);
  }
}

List::List(const List &other) {
  head = nullptr;
  copyElementsFromList(other);
}

List &List::operator=(const List &other) {
  free();
  head = nullptr;
  copyElementsFromList(other);

  return *this;
}

void List::print() const {
  for (Node *ptr = head; ptr != nullptr; ptr = ptr->next) {
    std::cout << ptr->data << "->";
  }
  std::cout << "NULL\n";
}
