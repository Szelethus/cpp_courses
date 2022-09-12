#include <iostream>
#include "list.h"

void List::print() const {
  for (Node *ptr = head; ptr != nullptr; ptr = ptr->next) {
    std::cout << ptr->data << "->";
  }
  std::cout << "NULL\n";
}

