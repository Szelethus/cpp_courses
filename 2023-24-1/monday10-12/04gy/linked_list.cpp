#include <iostream>

struct Node {
  int data;
  Node *next;
};

struct List {
  Node *head = nullptr;
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

void free(List &l) {
  Node *ptr = l.head;
  while (ptr != nullptr) {
    Node *nextptr = ptr->next;
    delete ptr;
    ptr = nextptr;
  }
}

int main() {
  List l;
  push_back(l, 5);
  push_back(l, 6);
  push_back(l, 7);
  free(l);
}
