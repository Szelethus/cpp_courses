#include <iostream>

struct Node {
  int data;
  Node *next;
};

struct List {
  Node *head;

  List() {
    this->head = nullptr;
  }
};

void push_back(List &l, int data) {
  if (l.head == nullptr) {
    l.head = new Node{data, nullptr};
    return;
  }

  Node *ptr = l.head;

  while (ptr->next != nullptr) {
    ptr = ptr->next;
  }

  ptr->next = new Node{data, nullptr};
}

int main() {
  List l;

  push_back(l, 5);

  // FIXME: MEMORY LEAK
}
