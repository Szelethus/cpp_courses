#include <iostream>
#include "list.h"
#include "header.h"

void List::free() {
  Node *current = head;

  while (current != NULL) {
    Node *tmp = current->next;
    delete current;
    current = tmp;
  }
}

void List::copyElements(const List &other) {
  if (other.head == NULL)
    return;

  Node *ptr = other.head;

  while (ptr != NULL) {
    add(ptr->data);
    ptr = ptr->next;
  }
}

List::List(int size) : head(NULL) {
  for (int i = 0; i < size; i++)
    add(0);
}

List &List::operator=(const List &other) {
  if (this == &other)
    return *this;

  free();
  head = NULL;
  copyElements(other);

  return *this;
}

void List::add(int newData) {
  if (head == NULL) {
    head = new Node(newData);
    return;
  }

  Node *ptr = head;

  while (ptr->next != NULL) {
    ptr = ptr->next;
  }

  ptr->next = new Node(newData);
}

std::ostream& operator<<(std::ostream &out, const List &l) {
  for (auto it = l.begin(); it != l.end(); ++it) {
    std::cout << *it << "->";
  }
  std::cout << "NULL\n";

  return out;
}

