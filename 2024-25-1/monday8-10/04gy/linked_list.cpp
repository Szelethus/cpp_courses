#include <iostream>

struct Node {
  int data;
  Node *next;
};

struct List {
  Node *head = nullptr;

  List() {}

  void display() {
    Node *ptr = head;
    while (ptr) {
      std::cout << ptr->data << '\n';
      ptr = ptr->next;
    }
  }

  void push_back(int data) {
    Node **ptr = &head;
    while (*ptr)
      ptr = &(*ptr)->next;
    *ptr = new Node{data, nullptr};
  }

  void free() {
    Node *ptr = head;
    while (ptr) {
      Node *nextPtr = ptr->next;
      delete ptr;
      ptr = nextPtr;
    }
  }
};

int main() {
  List l;
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  l.display();

  l.free();
}