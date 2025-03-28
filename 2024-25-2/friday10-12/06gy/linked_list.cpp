#include <iostream>

struct Node {
  int data;
  Node *next;
};

struct List {
  Node *head;

  List() : head(nullptr) {}

  void push_back(int data) {
    Node **ptr = &this->head;

    while (*ptr != nullptr) {
      ptr = &(*ptr)->next;
    }

    *ptr = new Node{data, nullptr};
  }

  void free() {
    Node *ptr = this->head;

    while (ptr != nullptr) {
      Node *nextPtr = ptr->next;
      delete ptr;
      ptr = nextPtr;
    }
  }

  void display() {
    Node *ptr = this->head;
    while (ptr != nullptr) {
      std::cout << ptr->data << '\n';
      ptr = ptr->next;
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
