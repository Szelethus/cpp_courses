#include <iostream>

struct Node {
  int data;
  Node *next;
};

class Iterator {
  Node *ptr;

public:
  Iterator(Node *_ptr) : ptr(_ptr) {}

  Iterator operator++() {
    ptr = ptr->next;
    return *this;
  }

  bool operator!=(const Iterator other) {
    return ptr != other.ptr;
  }

  bool operator==(const Iterator other) {
    return !(*this != other);
  }

  int operator*() {
    return ptr->data;
  }
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

  Iterator begin() {
    return Iterator{head};
  }

  Iterator end() {
    return Iterator{nullptr};
  }

  // copy konstruktor (List l2 = l)
  List(const List &other) {
    for (Iterator it = this->begin();
         it != this->end(); ++it) {
      push_back(*it);
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
