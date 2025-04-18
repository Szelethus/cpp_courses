#include <iostream>
struct Node {
  int data;
  Node *next;
};

struct List {
  Node *head;

  List() : head(nullptr) {}

  void push_back(int data) {
    Node **ptr = &head;
    while (*ptr != nullptr)
      ptr = &(*ptr)->next;

    *ptr = new Node{data, nullptr};
  }

  void free() {
    Node *ptr = head;

    while (ptr != nullptr) {
      Node *nextPtr = ptr->next;
      delete ptr;
      ptr = nextPtr;
    }
  }

  void display() {
    Node *ptr = head;
    while (ptr != nullptr) {
      std::cout << ptr->data << '\n';
      ptr = ptr->next;
    }
  }
};

int main() {
  List l;

  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  l.display();

  l.free();
}
