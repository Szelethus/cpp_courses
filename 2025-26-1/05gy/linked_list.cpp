#include <iostream>

struct Node {
  int data;
  Node *next;
};

struct List {
  Node *head = nullptr;

  // konstruktor
  List() = default;

  // destruktor
  ~List() {
    free();
  }

  // másoló konstruktor
  List(const List &other) {
    Node *ptr = other.head;
    while (ptr != nullptr) {
      push_back(ptr->data);
      ptr = ptr->next;
    }
  }

  // értékadó operátor
  List& operator=(const List &other) {
    if (this == &other)
      return *this;

    free();
    head = nullptr;

    Node *ptr = other.head;
    while (ptr != nullptr) {
      push_back(ptr->data);
      ptr = ptr->next;
    }
    
    return *this;
  }

  void push_back(int data) {
    Node **ptr = &head;
    while (*ptr != nullptr)
      ptr = &(*ptr)->next;
    
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
    while (ptr != nullptr) {
      Node *nextPtr = ptr->next;
      delete ptr;
      ptr = nextPtr;
    }
  }
};

void foo(List &l1, List &l2) {
  l1 = l2;
}

int main() {
  List l;
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  l.display();

  List l2 = l;
  l2 = l;

  foo(l2, l2);

  std::cout << '\n';

  l2.display();
}
