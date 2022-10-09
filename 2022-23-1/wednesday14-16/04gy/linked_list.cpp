#include <iostream>

struct Node {
  int data;
  Node *next;

  Node(int _data, Node *_next) : data(_data), next(_next) {}
};

class List {
public:
  Node *head = nullptr;

  List() {} // TODO
};

void display(List &l) {
  for (Node *ptr = l.head; ptr != nullptr; ptr = ptr->next) {
    std::cout << (*ptr).data << '\n';
  }
}

void push_back(List &l, int data) {
  Node **ptr = &l.head;
  while (*ptr != nullptr) {
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

int main() {
  List l{};
  push_back(l, 5);
  push_back(l, 6);
  push_back(l, 7);

  display(l);

  free(l);
}
