#include <iostream>

//===------------------------------------===//
// Node
//===------------------------------------===//

struct Node {
  int data;
  Node *next;
};

//===------------------------------------===//
// ConstIterator
//===------------------------------------===//

class ConstIterator {
  const Node *ptr;

public:
  ConstIterator(const Node *_ptr) : ptr(_ptr) {}

  // prefix++
  ConstIterator operator++() {
    ptr = ptr->next;
    return *this;
  }

  // postfix++
  ConstIterator operator++(int) {
    ConstIterator ret = *this;
    ptr = ptr->next;
    return *this;
  }

  bool operator==(ConstIterator other) {
    return ptr == other.ptr;
  }

  bool operator!=(ConstIterator other) {
    return !(*this == other);
  }

  // TODO: mi van ha ez egyszer nagyobb lesz?
  int operator*() {
    return ptr->data;
  }
};

//===------------------------------------===//
// Iterator
//===------------------------------------===//

class Iterator {
  Node *ptr;

public:
  Iterator(Node *_ptr) : ptr(_ptr) {}

  // konverziós opearátor
  operator ConstIterator() {
    return ConstIterator{ptr};
  }

  // prefix++
  Iterator operator++() {
    ptr = ptr->next;
    return *this;
  }

  // postfix++
  Iterator operator++(int) {
    Iterator ret = *this;
    ptr = ptr->next;
    return *this;
  }

  bool operator==(Iterator other) {
    return ptr == other.ptr;
  }

  bool operator!=(Iterator other) {
    return !(*this == other);
  }

  int &operator*() {
    return ptr->data;
  }
};

//===------------------------------------===//
// List
//===------------------------------------===//

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
  List() = default;

  ~List() { free(); }

  List(const List &other) {
    Node *ptr = other.head;
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

    Node *ptr = other.head;
    while (ptr) {
      push_back(ptr->data);
      ptr = ptr->next;
    }
    return *this;
  }

  Iterator begin() {
    return Iterator(head);
  }

  Iterator end() {
    return Iterator(nullptr);
  }

  ConstIterator begin() const {
    return ConstIterator(head);
  }

  ConstIterator end() const {
    return ConstIterator(nullptr);
  }

  void push_back(int data) {
    Node **ptr = &head;

    while (*ptr)
      ptr = &(*ptr)->next;

    *ptr = new Node{data, nullptr};
  }

  void display() const {
    for (ConstIterator it = begin(); it != end(); ++it) {
      std::cout << *it << '\n';
    }
  }
};

int main() {
  List l;
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);

  ConstIterator it = l.begin();

  const List l2 = l;

  l2.display();
}
