#include <iostream>

struct Node {
  int data;
  Node *next;
};

struct List {
  Node *head;

  List() {
    head = nullptr;
  }
};

void push_back(List &l, int data) {
  Node **ptr = &l.head;

  while (*ptr != nullptr) {
    ptr = &(*ptr)->next;
  }

  *ptr = new Node{data, nullptr};
}

void print(List &l) {
  Node *ptr = l.head;
  while (ptr != nullptr) {
    std::cout << ptr->data << '\n';
    ptr = ptr->next;
  }
}

int main() {
  List l;

  push_back(l, 5);
  push_back(l, 6);
  push_back(l, 7);

  print(l);

  delete l.head->next->next;
  delete l.head->next;
  delete l.head;
}
