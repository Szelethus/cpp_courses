#include <iostream>

struct Node {
  int data;
  Node *next;
};

class List {
  Node *head = nullptr;

public:
  List() = default;

  ~List() { free(); }

  List(const List &other) {
    const Node *ptr = other.head;
    while (ptr) {
      push_back(ptr->data);
      ptr = ptr->next;
    }
  }

  List &operator=(const List &other) {
    if (this == &other)
      return *this;
    free();
    head = nullptr;
    const Node *ptr = other.head;
    while (ptr) {
      push_back(ptr->data);
      ptr = ptr->next;
    }
    return *this;
  }

  void push_back(int data) {
    Node **ptr = &head;
    while (*ptr != nullptr) {
      ptr = &(*ptr)->next;
    }
    *ptr = new Node{data, nullptr};
  }

  void display() {
    Node *ptr = head;
    while (ptr != nullptr) {
      std::cout << ptr->data << '\n';
      ptr = ptr->next;
    }
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
  l.push_back(4);
  l.push_back(4);
  l.push_back(4);
  l.push_back(4);
  l.push_back(4);
  l.display();
  List l2 = l;
  l2 = l;
  
}
