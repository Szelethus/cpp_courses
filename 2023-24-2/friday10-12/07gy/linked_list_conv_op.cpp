#include <iostream>

//===---------------------------------===//
// Node
//===---------------------------------===//

struct Node {
  int data;
  Node *next;
};

//===---------------------------------===//
// Iterators
//===---------------------------------===//

class ConstIterator;

class Iterator {
  Node *ptr;

public:
  Iterator(Node *_ptr) : ptr(_ptr) {}

  operator ConstIterator();

  // Prefix++
  Iterator operator++() {
    ptr = ptr->next;
    return *this;
  }
  // Postfix++
  Iterator operator++(int) {
    Iterator ret = *this;
    ptr = ptr->next;
    return ret;
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

class ConstIterator {
  const Node *ptr;

public:
  ConstIterator(const Node *_ptr) : ptr(_ptr) {}

  // Prefix++
  ConstIterator operator++() {
    ptr = ptr->next;
    return *this;
  }
  // Postfix++
  ConstIterator operator++(int) {
    ConstIterator ret = *this;
    ptr = ptr->next;
    return ret;
  }

  bool operator==(ConstIterator other) {
    return ptr == other.ptr;
  }

  bool operator!=(ConstIterator other) {
    return !(*this == other);
  }

  // TODO: What if the return value size is much greater?
  int operator*() {
    return ptr->data;
  }
};

Iterator::operator ConstIterator() {
  return ConstIterator(ptr);
}

//===---------------------------------===//
// List
//===---------------------------------===//

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

  Iterator it = l.begin();
  ConstIterator cit = it;

  const List l2 = l;

  l2.display();
}
