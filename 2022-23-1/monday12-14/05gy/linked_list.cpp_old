#include <iostream>

struct Node {
  int data;
  Node *next;

  Node(int _data, Node *_next) : data(_data), next(_next) {}
};

class iterator {
  Node *ptr;

public:
  iterator(Node *ptr) : ptr(ptr) {}

};

class List {
  Node *head = nullptr;

  void free() {
    Node *ptr = head;
    while (ptr != nullptr) {
      Node *nextPtr = ptr->next;
      delete ptr;
      ptr = nextPtr;
    }
  }

public:
  List() = default;
  ~List() { free(); }
  List(const List &other) {
    for (const Node *ptr = other.head; ptr != nullptr; ptr = ptr->next) {
      push_back(ptr->data);
    }
  }
  List &operator=(const List &other) {
    if (this == &other)
      return *this;

    free();
    head = nullptr;

    for (const Node *ptr = other.head; ptr != nullptr; ptr = ptr->next) {
      push_back(ptr->data);
    }
    return *this;
  }

  void push_back(int data) {
    Node **ptr = &head;
    while ((*ptr) != nullptr) {
      ptr = &(*ptr)->next;
    }
    *ptr = new Node{data, nullptr};
  }

  void print() {
    for (Node *ptr = head; ptr != nullptr; ptr = ptr->next) {
      std::cout << (*ptr).data << '\n';
    }
  }
};

int main() {
  List l;
  List l2 = l;
  l.push_back(5);
  l = l2;
  l.push_back(6);
  l.push_back(7);

  l.print();
}
