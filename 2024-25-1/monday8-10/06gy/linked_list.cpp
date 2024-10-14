#include <iostream>

struct Node {
  int data;
  Node *next;
};

class List {
  Node *head = nullptr;

  void free() {
    Node *ptr = head;
    while (ptr) {
      Node *nextPtr = ptr->next;
      delete ptr;
      ptr = nextPtr;
    }
  }

public:
  // (default) konstruktor
  List() = default;

  // destruktor
  ~List() {
    free();
  }

  // copy konstruktor (List l2 = l)
  List(const List &other) {
    Node *ptr = other.head;
    while (ptr) {
      push_back(ptr->data);
      ptr = ptr->next;
    }
  }

  // értékadó operátor (l2 = l)
  List &operator=(const List &other) {
    if (this == &other)
      return *this;

    free();
    head = nullptr;

    Node *ptr = other.head;
    while (ptr) {
      push_back(ptr->data);
      ptr = ptr->next;
    }
    return *this;
  }

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
};

void foo(List &l1, List &l2) {
  l1 = l2;
}

int main() {
  List l;
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  //l.display();

  List l2(l);
  l2 = l;

  l2.display();
}
