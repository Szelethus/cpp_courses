#include <iostream>

struct Node {
  int data;
  Node *next;
};

struct List {
  Node *head = nullptr;
};

void push_back(List &l, int data) {
  Node **ptr = &l.head;
  while (*ptr != nullptr)
    ptr = &(*ptr)->next;
  *ptr = new Node{data, nullptr};
}

int main() {
  List l;
  push_back(l, 5);
  push_back(l, 6);
  push_back(l, 7);
}
