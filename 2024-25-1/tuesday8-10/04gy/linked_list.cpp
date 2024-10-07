#include <iostream>

struct Node {
  int data;
  Node *next;
};

struct List {
  Node *head = nullptr;

  void display() {
    Node *ptr = this->head;
    while (ptr) {
      std::cout << ptr->data << '\n';
      ptr = ptr->next;
    }
  }
};

void push_back(List &l, int data) {
  if (l.head == nullptr) {
    l.head = new Node{data, nullptr};
    return;
  }

  Node *ptr = l.head;
  while (ptr->next != nullptr)
    ptr = ptr->next;
  ptr->next = new Node{data, nullptr};
}

void free(List &l) {
  Node *ptr = l.head;
  while (ptr) {
    Node *nextPtr = ptr->next;
    delete ptr;
    ptr = nextPtr;
  }
}

int main() {
  List l;
  l.head = nullptr;
  push_back(l, 5);
  push_back(l, 6);
  push_back(l, 7);

  l.display();

  free(l);
}
