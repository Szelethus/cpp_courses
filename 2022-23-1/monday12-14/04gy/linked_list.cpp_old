#include <iostream>

struct Node {
  int data;
  Node *next;
};

class List {
public:
  Node *head = nullptr;
};

void add(List &l, int data) {
  Node **ptr = &l.head;
  while ((*ptr) != nullptr) {
    ptr = &(*ptr)->next;
  }
  *ptr = new Node{data, nullptr};
}

void free(List &l) {
  Node *ptr = l.head;
  while (ptr != nullptr) {
    Node *nextPtr = ptr->next;
    delete ptr;
    ptr = nextPtr;
  }
}

void display(List &l) {
  for (Node *ptr = l.head; ptr != nullptr; ptr = ptr->next) {
    std::cout << ptr->data << '\n';
  }
}

int main() {

  List l;
  add(l, 3);
  add(l, 3);
  add(l, 3);
  add(l, 3);
  add(l, 3);
  display(l);
  free(l);
}
